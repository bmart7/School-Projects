/***********************************************************
 Brian Martin (A56350138)
 Project #4
***********************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

void *sourceExternal(void* str);
void exit_cmd(bool* exit);
void help();
void now();
void env();
void path();
void cwd();
void cd(vector<string> tokens);
void set(vector<string> tokens);
void read(vector<string> inlineTokens, bool * exit);
void unknown(vector<string> tokens, string line, char * buffer);

vector<string> commands = {"exit", "help", "now", "env", "path", "cwd", "cd", "set", "read"};
extern char **environ;
const int LINE_SIZE = 128;
const char* PROMPT = "[%s %i] ";
const char* USER_ID = cuserid(NULL);

/***********************************************************
 Name: main

 Purpose: Emulates a basic Command Line Interpreter (shell)
 Recieves: Run-time input from user containing keyword commands
 Returns: Boolean success or fail
***********************************************************/

int main(){

	
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
				exit_cmd(&exit);
				break;
			}

			case 1 : //help
			{
				help();
				break;
			}

			case 2 : //now
			{
				now();
				break;
			}

			case 3 : //env
			{
				env();
				break;
			}

			case 4 : //path
			{
				path();
				break;
			}
			case 5 : //cwd
			{
				cwd();
				break;
			}
			case 6 : //cd
			{
				cd(tokens);
				
				break;
			}
			case 7 : //set
			{
				set(tokens);
				break;
			}
			case 8 : //read
			{
				read(tokens, &exit);
				break;
			}
			case -1 : //unknown command
			{
				char buffer[LINE_SIZE];
				unknown(tokens, line, buffer);
				break;
			}
		}

		counter++;

	}
	
}

/***********************************************************
 Name: sourceExternal

 Purpose: Sources External Commands for Shell in main
 Recieves: Arguments for the External Command in type void*
 Returns: void
***********************************************************/
void *sourceExternal(void* str){

	const char* temp;
	temp = (const char*) str;
	string line(temp);
	int success = system(line.c_str());
	if (success != 0){
		cout<<"External Command Failed - Non-Zero Return Value"<<endl;
	}
	pthread_exit(NULL);
}

/***********************************************************
 Name: exit_cmd

 Purpose: Sets exit flag to true
 Recieves: Pointer to exit flag
 Returns: void
***********************************************************/
void exit_cmd(bool * exit){
	*exit = true;
}

/***********************************************************
 Name: help

 Purpose: Display built in commands
 Recieves: 
 Returns: void
***********************************************************/
void help(){
	cout<<"\nexit\t\tterminate the shell process"<<endl<<
		"help\t\tdisplay built-in commands "<<endl<<
		"now\t\tdisplay current date and time"<<endl<<
		"env\t\tdisplay environment variables"<<endl<<
		"path\t\tdisplay current search path"<<endl<<
		"cwd\t\tdisplay absolute pathname of current working directory"<<endl<<
		"cd\t\tmanage current working directory\n"<<
		"set\t\tmanage environment variables"<<endl<<
		"read\t\timport commands from a file"<<endl<<endl;
}

/***********************************************************
 Name: now

 Purpose: Display current date and time
 Recieves: 
 Returns: void
***********************************************************/
void now(){
	time_t now;
	time(&now);
	printf("\n%s\n", ctime(&now));
}

/***********************************************************
 Name: env

 Purpose: Display Environment Variables
 Recieves: 
 Returns: void
***********************************************************/
void env(){
	for (char **env = environ; *env; env++){
		char* currentEnv = *env;
		printf("%s\n", currentEnv);
	}
}

/***********************************************************
 Name: path

 Purpose: Display current search path
 Recieves: 
 Returns: void
***********************************************************/
void path(){
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
}

/***********************************************************
 Name: cwd

 Purpose: Display Current Working Directory
 Recieves: 
 Returns: void
***********************************************************/
void cwd(){
	char buffer[LINE_SIZE];
	getcwd(buffer, LINE_SIZE);
	printf("%s\n", buffer);
}

/***********************************************************
 Name: cd

 Purpose: Facilitates changing Current Working Directory for shell
 Recieves: String vector containg tokens from input line
 Returns: void
***********************************************************/
void cd(vector<string> tokens){
	if (tokens.size() < 2 || tokens[1].compare("~") == 0){
		string path = "/user/";
		path += USER_ID;
		int success = chdir(path.c_str());
		if (success != 0){
			cout<<"Problem Changing Directory to User Home"<<endl;
		}
		success = setenv("PWD", path.c_str(), 1);
		if (success != 0){
			cout<<"Problem Setting PWD Environment Variable"<<endl;
		}
	}
	else if (tokens[1].at(0) == '~'){
		string path = "/user/" + tokens[1].substr(1);
		int success = chdir(path.c_str());
		if (success != 0){
			cout<<"Invalid User's Directory"<<endl;
		}
		success = setenv("PWD", path.c_str(), 1);
		if (success != 0){
			cout<<"Problem Setting PWD Environment Variable"<<endl;
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
			success = setenv("PWD", tokens[1].c_str(), 1);
			if (success != 0){
				cout<<"Problem Setting PWD Environment Variable"<<endl;
			}
		}
		else{
			success = setenv("PWD", path.c_str(), 1);
			if (success != 0){
				cout<<"Problem Setting PWD Environment Variable"<<endl;
			}
		}
	}
}

/***********************************************************
 Name: set

 Purpose: Facilitates setting/removing Environment Variables
 Recieves: String vector containg tokens from input line
 Returns: void
***********************************************************/
void set(vector<string> tokens){
	if (tokens.size() == 3){
		int success = setenv(tokens[1].c_str(), tokens[2].c_str(), 1);
		if (success !=0){
			cout<<"Problem Setting Environment Variable "<<tokens[1]<<endl;
		}
	}
	else if (tokens.size() == 2){
		int success = unsetenv(tokens[1].c_str());
		if (success != 0){
			cout<<"Problem Unsetting Environment Variable "<<tokens[1]<<endl;
		}
	}
	else{
		cout<<"Invalid Amount of Tokens"<<endl;
	}
}

/***********************************************************
 Name: unknown

 Purpose: Facilitates Sourcing External Commands
 Recieves: String vector containg tokens from input line
	   String input line
	   Allocated space as buffer for threading
 Returns: void
***********************************************************/
void unknown(vector<string> tokens, string line, char * buffer){
	pthread_t thread;
	bool wait = true;
	string temp = tokens[tokens.size()-1];
	if (temp.compare("&") == 0 || temp.at(temp.length()-1) == '&'){
		wait = false;
		line = line.substr(0,line.length()-1);
	}
	strcpy(buffer,line.c_str());
	int success = pthread_create(&thread, NULL, sourceExternal, (void*) buffer);
	if (success != 0){
		cout<<"Problem Sourcing External Command - Error Creating Thread"<<endl;
	}else if (wait){
		success = pthread_join(thread, NULL);
		if (success != 0){
			cout<<"Problem Sourcing External Command - Error Joining Thread"<<endl;
		}
	}
}

/***********************************************************
 Name: read

 Purpose: Facilitates reading and executing script for shell
 Recieves: String vector containg tokens from input line
	   Pointer to exit flag
 Returns: void
***********************************************************/
void read(vector<string> inlineTokens, bool * exit){
	if (inlineTokens.size() > 2){
		cout<<"Invalid Amount of Arguments"<<endl;
	}else{
		ifstream infile(inlineTokens[1]);
		if (!infile){
			cout<<"Problem Opening File"<<endl;
		}else{
			string line;
			while (getline(infile,line)){
				cout<<line<<endl;
				if (line.length() > LINE_SIZE-1){
					cout<<"Exceeded Maximum Line Size"<<endl;
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
						exit_cmd(exit);
						break;
					}

					case 1 : //help
					{
						help();
						break;
					}

					case 2 : //now
					{
						now();
						break;
					}

					case 3 : //env
					{
						env();
						break;
					}

					case 4 : //path
					{
						path();
						break;
					}
					case 5 : //cwd
					{
						cwd();
						break;
					}
					case 6 : //cd
					{
						cd(tokens);
						
						break;
					}
					case 7 : //set
					{
						set(tokens);
						break;
					}
					case 8 : //read
					{
						read(tokens, exit);
						break;
					}
					case -1 : //unknown command
					{
						char buffer[LINE_SIZE];
						unknown(tokens, line, buffer);
						break;
					}
				}
			}
		}
	}
}
