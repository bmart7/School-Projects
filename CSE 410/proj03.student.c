/***********************************************************
 Brian Martin (A56350138)
 Project #3
***********************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

/***********************************************************
 Name: main

 Purpose: Emulates a basic Command Line Interpreter (shell)
 Recieves: Run-time input from user containing keyword commands
 Returns: Boolean success or fail
***********************************************************/

int main(){

	vector<string> commands = {"exit", "help", "now", "env", "path", "cwd", "cd"};
	extern char **environ;
	const int LINE_SIZE = 128;
	const char* PROMPT = "[%s %i] ";
	const char* USER_ID = cuserid(NULL);
	int counter = 1;
	bool exit = false;

	while (!exit){

		printf(PROMPT, USER_ID, counter);

		string line;
		getline(cin,line);
		if (line.length() > LINE_SIZE-1){
			cout<<"Exceeded Maximum Line Size"<<endl;
			counter++;
			continue;
		}

		istringstream buffer(line);
    	vector<string> tokens;
    	copy(istream_iterator<string>(buffer), 
        			istream_iterator<string>(),
      				back_inserter(tokens));
		if (tokens.size() == 0){
			continue;
		}

		int commandNum = -1;
		for (int i = 0; i < commands.size(); i++){
			if (tokens[0].compare(commands[i]) == 0){
				commandNum = i;
			}
		}

		switch(commandNum){

			case 0 : //exit
			{
				exit = true;
				break;
			}

			case 1 : //help
			{
				cout<<"\nexit\t\tterminate the shell process"<<endl<<
					"help\t\tterminate the shell process"<<endl<<
					"now\t\tdisplay current date and time"<<endl<<
					"env\t\tdisplay environment variables"<<endl<<
					"path\t\tdisplay current search path"<<endl<<
					"cwd\t\tdisplay absolute pathname of current working directory"<<endl<<
					"cd\t\tmanage current working directory\n"<<endl;
				break;
			}

			case 2 : //now
			{
				time_t now;
				time(&now);
				printf("\n%s\n", ctime(&now));
				break;
			}

			case 3 : //env
			{
				for (char **env = environ; *env; env++){
					char* currentEnv = *env;
					printf("%s\n", currentEnv);
				}
				break;
			}

			case 4 : //path
			{
				char* pathc = getenv("PATH");
				string path(pathc);
				int start = 0;
				int pos;
				while ((pos = path.find(":", start)) != string::npos)
				{
					cout<<path.substr(start, pos-start)<<endl;
					start = pos + 1;
				}
					cout<<path.substr(start)<<endl;
				break;
			}
			case 5 : //cwd
			{
				char buffer[LINE_SIZE];
				getcwd(buffer, LINE_SIZE);
				printf("%s\n", buffer);
				break;
			}
			case 6 : //cd
			{
				if (tokens.size() < 2 || tokens[1].compare("~") == 0){
					string path = "/user/";
					path += USER_ID;
					int success = chdir(path.c_str());
					if (success != 0){
						cout<<"Problem Changing Directory to User Home"<<endl;
					}
				}
				else if (tokens[1].at(0) == '~'){
					string path = "/user/" + tokens[1].substr(1);
					int success = chdir(path.c_str());
					if (success != 0){
						cout<<"Invalid User's Directory"<<endl;
					}
				}
				else{
					char buffer[LINE_SIZE];
					string path(getcwd(buffer,LINE_SIZE));
					path += "/" + tokens[1];
					int success = chdir(path.c_str()); //Attempt as relative path
					if (success != 0){
						success = chdir(tokens[1].c_str()); //Attempt as full path
						if (success != 0){
							cout<<"Invalid Directory"<<endl;
						}
					}
				}
				
				break;
			}
			case -1 : //unknown command
				cout<<"Invalid Command"<<endl;
				break;
		}

		counter++;

	}
	

}
