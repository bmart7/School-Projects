/***********************************************************
 Brian Martin (A56350138)
 Project #7
***********************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

int collectArgs(const int& argc, char* argv[]);
int getRAM();
int processMemRef();
void printRAM();
void printCache();

bool DEFAULT_RAM_FLAG = true;
bool DEBUG_FLAG = false;
string RAM_FILE = "";
string REF_FILE = "";
int RAM_SUBSECT = 0;
int LINE_COUNT = 0;
int OFFSET_MASK = 0x000f;
int LINE_MASK = 0x0070;
int LINE_SHIFT = 4;
int ADDR_TAG_MASK = 0xff80;
int ADDR_TAG_SHIFT = 7;
int CACHE_TAG_MASK = 0x1ff;
int M_MASK = 0x200;
int M_SHIFT = 9;
int V_MASK = 0x400;
int V_SHIFT = 10;

struct entry{
	int control;
	unsigned char data[16];
};

struct entry cache[8];
unsigned char RAM[65563];

/***********************************************************
 Name: main

 Purpose: Emulates Transfer of Data Between RAM and Cache
 Recieves: Command line arguments
			RAM File Location
			Memory Reference File Location
			Debug Flag
 Returns: Boolean success or fail
***********************************************************/
int main(int argc, char* argv[]){

	int success = collectArgs(argc, argv);
	if (!success) return 0;

	if (RAM_FILE.compare("") != 0){
		success = getRAM();
	}
	if (!success) return 0;

	if (DEBUG_FLAG){
		printRAM();
		printCache();
	}

	success = processMemRef();
	if (!success) return 0;

	printRAM();
	printCache();

}

/***********************************************************
 Name: processMemRef

 Purpose: Reads instructions from Memory Reference File
 Recieves: None
 Returns: Integer success value
***********************************************************/
int processMemRef(){

	ifstream infile(REF_FILE);
	if (infile){
		string line;
		while (getline(infile,line)){
			istringstream iss(line);
			vector<string> tokens;
    		copy(istream_iterator<string>(iss), 
        			istream_iterator<string>(),
      				back_inserter(tokens));
			int address = strtoul(tokens[0].c_str(),NULL,16);
			int offset = (address & OFFSET_MASK);
			int index = ((address & LINE_MASK) >> LINE_SHIFT);
			int tag = ((address & ADDR_TAG_MASK) >> ADDR_TAG_SHIFT);
			if (tokens[1].compare("R") == 0){
				printf("%04x R %0x %03x %0x\n",address,index,tag,offset);
			}else{
				printf("%04x W %0x %03x %0x\n",address,index,tag,offset);
			}
			if (DEBUG_FLAG) printCache();
		}
	}else{
		cout<<"Could Not Open Memory Reference File ==> \""<<REF_FILE<<"\""<<endl;
		return 0;
	}

}

/***********************************************************
 Name: printCache

 Purpose: Prints Cache Contents
 Recieves: None
 Returns: None
***********************************************************/
void printCache(){

	cout<<endl;
	for (int i=0; i<8; i++){
		int v = ((cache[i].control & V_MASK) >> V_SHIFT);
		int m = ((cache[i].control & M_MASK) >> M_SHIFT);
		int tag = (cache[i].control & CACHE_TAG_MASK);
		printf("%0x %0x %0x %03x",i,v,m,tag);
		for (int j=0; j<16; j++){
			printf(" %02x",cache[i].data[j]);
		}
		cout<<endl;
	}
	cout<<endl;
}

/***********************************************************
 Name: printRAM

 Purpose: Prints RAM Contents
 Recieves: None
 Returns: None
***********************************************************/
void printRAM(){

	if (DEFAULT_RAM_FLAG) return;
	cout<<endl;
	int start = RAM_SUBSECT;
	for (int i=0; i<LINE_COUNT; i++){
		printf("%04x",start);
		for (int j=0; j<16; j++){
			printf(" %02x",RAM[start+j]);
		}
		cout<<endl;
		start += 16;
	}
	cout<<endl;
}

/***********************************************************
 Name: getRAM

 Purpose: Reads information from RAM File
 Recieves: None
 Returns: Integer success value
***********************************************************/
int getRAM(){

	ifstream infile(RAM_FILE);
	if (infile){
		DEFAULT_RAM_FLAG = false;
		string temp;
		getline(infile,temp);
		RAM_SUBSECT = strtoul(temp.c_str(),NULL,16);
		if (RAM_SUBSECT % 16 != 0){
			printf("Starting Address Invalid ==> %04x",RAM_SUBSECT);
			return 0;
		}
		int start = RAM_SUBSECT;
		string line;
		while (getline(infile,line)){
			LINE_COUNT++;
			istringstream iss(line);
			vector<string> tokens;
    		copy(istream_iterator<string>(iss), 
        			istream_iterator<string>(),
      				back_inserter(tokens));
			for (int i=0; i<tokens.size();i++){
				RAM[start + i] = strtoul(tokens[i].c_str(),NULL,16);
			}
			start += tokens.size();
		}
	}else{
		cout<<"Could Not Open RAM File ==> \""<<RAM_FILE<<"\"\n\tContinuing With Empty RAM\n"<<endl;
	}
	return 1;
}

/***********************************************************
 Name: collectArgs

 Purpose: Reads information from command line arguments
 Recieves: Main function input
 Returns: Integer success value
***********************************************************/
int collectArgs(const int& argc, char* argv[]){

	for (int i=1; i<argc; i++){
		if (argv[i][0] == '-'){
			string token(argv[i]);
			token = token.substr(1);
			if (token.compare("ram") == 0){
				string ramFile = "";
				if (i+1 < argc){
					ramFile = string(argv[i+1]);
				}else{
					cout<<"No RAM File Given After Flag"<<endl;
					return 0;
				}
				if (ramFile.at(0) == '-'){
					cout<<"No RAM File Given After Flag"<<endl;
					return 0;
				}else{
					RAM_FILE = ramFile;
					i++;
				}
			}else if (token.compare("refs") == 0){
				string refFile = "";
				if (i+1 < argc){
					refFile = string(argv[i+1]);
				}else{
					cout<<"No Memory Reference File Given"<<endl;
					return 0;
				}
				if (refFile.at(0) == '-'){
					cout<<"No Memory Reference File Given"<<endl;
					return 0;
				}else{
					REF_FILE = refFile;
					i++;
				}
			}else if (token.compare("debug") == 0){
				DEBUG_FLAG = true;
			}else{
				cout<<"Invalid Command Line Argument ==> \"-"<<token<<"\""<<endl;
				return 0;
			}
		}else{
			cout<<"Invalid Command Line Argument ==> \"-"<<argv[i]<<"\""<<endl;
			return 0;
		}
	}
	if (REF_FILE.compare("") == 0){
		cout<<"No Memory Reference File Given"<<endl;
		return 0;
	}
	return 1;
}
