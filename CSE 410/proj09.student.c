/***********************************************************
 Brian Martin (A56350138)
 Project #9
***********************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

void initializeTable();
int processArgs(const int& argc, char* argv[]);
int getRefs();
void printTable();

struct entry{
	unsigned char control;
	unsigned short frame;
};
const int TABLE_SIZE = 8;
struct entry PTable[TABLE_SIZE];
bool DEBUG_FLAG = false;
string REF_FILE = "";
int READ_COUNT = 0;
int WRITE_COUNT = 0;
const unsigned short PAGE_MASK = 0xe000;
const unsigned short PAGE_SHIFT = 13;
const unsigned short OFFSET_MASK = 0x1fff;
const unsigned short V_MASK = 0x4;
const unsigned short V_SHIFT = 2;
const unsigned short R_MASK = 0x2;
const unsigned short R_SHIFT = 1;
const unsigned short M_MASK = 0x1;
const string TABLE_HEADER = "I V R M Frame\n-------------\n";

/***********************************************************
 Name: main

 Purpose: Emulates Page Referencing For RAM Processes
 Recieves: Command line arguments
			Memory Reference File Location
			Debug Flag
 Returns: Boolean success or fail
***********************************************************/
int main(int argc, char* argv[]){

	initializeTable();

	int success = processArgs(argc, argv);
	if (success == 0) return 0;

	if (DEBUG_FLAG) printTable();

	success = getRefs();
	if (success == 0) return 0;

	cout<<endl<<"Read Operations: "<<READ_COUNT<<endl;
	cout<<"Write Operations: "<<WRITE_COUNT<<endl;
	cout<<"Memory References: "<<READ_COUNT + WRITE_COUNT<<endl;
	printTable();

}

/***********************************************************
 Name: printTable

 Purpose: Prints Page Table Contents
 Recieves: None
 Returns: None
***********************************************************/
void printTable(){

	cout<<endl<<TABLE_HEADER;
	for (int i = 0;i < TABLE_SIZE;i++){
		unsigned char v = ((PTable[i].control & V_MASK) >> V_SHIFT);
		unsigned char r = ((PTable[i].control & R_MASK) >> R_SHIFT);
		unsigned char m = (PTable[i].control & M_MASK);
		printf("%d %0x %0x %0x %03x\n",i,v,r,m,PTable[i].frame);
	}
	cout<<endl;

}

/***********************************************************
 Name: getRefs

 Purpose: Reads instructions from Memory Reference File
 Recieves: None
 Returns: Integer success value
***********************************************************/
int getRefs(){

	ifstream infile(REF_FILE);
	if (infile){
		string line;
		while (getline(infile,line)){
			istringstream iss(line);
			vector<string> tokens;
    		copy(istream_iterator<string>(iss), 
        			istream_iterator<string>(),
      				back_inserter(tokens));
			unsigned short address = strtoul(tokens[0].c_str(),NULL,16);
			unsigned short page = ((address & PAGE_MASK) >> PAGE_SHIFT);
			unsigned short offset = (address & OFFSET_MASK);
			if (tokens[1].compare("R") == 0){
				printf("%04x %d %04x R\n",address,page,offset);
				READ_COUNT++;
			}else{
				printf("%04x %d %04x W\n",address,page,offset);
				WRITE_COUNT++;
			}
			if (DEBUG_FLAG) printTable();
		}
	}else{
		cout<<"Could Not Open Memory Reference File ==> \""<<REF_FILE<<"\""<<endl;
		return 0;
	}
	return 1;

}

/***********************************************************
 Name: collectArgs

 Purpose: Reads information from command line arguments
 Recieves: Main function input
 Returns: Integer success value
***********************************************************/
int processArgs(const int& argc, char* argv[]){

	for (int i = 1; i < argc; i++){
		if (argv[i][0] == '-'){
			string token(argv[i]);
			token = token.substr(1);
			if (token.compare("refs") == 0){
				if (argv[i+1][0] == '-'){
					cout<<"No Memory Reference File Given After Flag"<<endl;
					return 0;
				}else{
					string temp(argv[i+1]);
					REF_FILE = temp;
					i++;
				}
			}else if (token.compare("debug") == 0){
				DEBUG_FLAG = true;
			}else{
				cout<<"Invalid Command Line Argument ==> \"-"<<token<<"\""<<endl;
				return 0;
			}
		}else{
			cout<<"Invalid Command Line Argument ==> \""<<argv[i]<<"\""<<endl;
			return 0;
		}
	}
	if (REF_FILE.compare("") == 0){
		cout<<"No Memory Reference File Given"<<endl;
		return 0;
	}
	return 1;

}

/***********************************************************
 Name: initializeTable

 Purpose: Initializes Page Table to 0's
 Recieves: None
 Returns: None
***********************************************************/
void initializeTable(){

	for (int i = 0; i < TABLE_SIZE; i++){
		PTable[i].control = 0;
		PTable[i].frame = 0;
	}

}

