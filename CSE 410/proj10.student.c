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
#include <queue>

using namespace std;

void initializeTable();
int processArgs(const int& argc, char* argv[]);
int getRefs();
void printTable();
bool pageIsValid(unsigned short page);
bool pageIsModified(unsigned short page);
bool pageIsReferenced(unsigned short page);
bool processPageFault(unsigned short page);
unsigned short determineVictim(unsigned short page);

struct entry{
	unsigned char control;
	unsigned short frame;
};
const int TABLE_SIZE = 8;
struct entry PTable[TABLE_SIZE];
vector<unsigned short> OPEN_TABLE;
queue<unsigned short> USED_QUEUE;
vector<unsigned short> CLOCK_BUFFER;
unsigned short CLOCK_INDEX = 0;
bool DEBUG_FLAG = false;
string REF_FILE = "";
int READ_COUNT = 0;
int WRITE_COUNT = 0;
int FAULT_COUNT = 0;
int WBACK_COUNT = 0;
int frameCount = 0;
const int FRAME_SIZE = 8192;
const unsigned short PAGE_MASK = 0xe000;
const unsigned short PAGE_SHIFT = 13;
const unsigned short OFFSET_MASK = 0x1fff;
const unsigned short V_MASK = 0x4;
const unsigned short V_SHIFT = 2;
const unsigned short R_MASK = 0x2;
const unsigned short R_SHIFT = 1;
const unsigned short M_MASK = 0x1;
const string TABLE_HEADER = "I V R M Frame\n-------------\n";
bool FIFO = false;
bool LRU = false;

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

	if (FIFO){
		cout<<endl<<"Replacement Algorithm: FIFO"<<endl;
	}else{
		cout<<endl<<"Replacement Algorithm: LRU"<<endl;
	}
	cout<<"Number of Frames Allocated: "<<frameCount<<endl;
	cout<<"Memory References: "<<READ_COUNT + WRITE_COUNT<<endl;
	cout<<"Read Operations: "<<READ_COUNT<<endl;
	cout<<"Write Operations: "<<WRITE_COUNT<<endl;
	cout<<"Page Faults: "<<FAULT_COUNT<<endl;
	cout<<"Write Backs: "<<WBACK_COUNT<<endl;
	printTable();

}

/***********************************************************
 Name: dereferencePage

 Purpose: Changes R bit of page number 'page' to 0
 Recieves: unsigned short page
 Returns: void
***********************************************************/
void dereferencePage(unsigned short page){

	PTable[page].control = (PTable[page].control & 0x5);

}

/***********************************************************
 Name: determineVictim

 Purpose: Determines page number to be expelled from RAM
 Recieves: unsigned short page
 Returns: unsigned short
***********************************************************/
unsigned short determineVictim(unsigned short page){

	if (FIFO){
		unsigned short next = USED_QUEUE.front();
		USED_QUEUE.pop();
		return next;
	}else{
		while (pageIsReferenced(CLOCK_BUFFER[CLOCK_INDEX])){
			dereferencePage(CLOCK_BUFFER[CLOCK_INDEX]);
			CLOCK_INDEX = (CLOCK_INDEX + 1) % CLOCK_BUFFER.size();
		}
		unsigned short victim = CLOCK_BUFFER[CLOCK_INDEX];
		CLOCK_BUFFER[CLOCK_INDEX] = page;
		CLOCK_INDEX = (CLOCK_INDEX + 1) % CLOCK_BUFFER.size();
		return victim;
	}
}

/***********************************************************
 Name: processPageFault

 Purpose: Simulates page fault at page number 'page' and 
			finds correct frame number
 Recieves: unsigned short page
 Returns: bool
***********************************************************/
bool processPageFault(unsigned short page){

	bool wroteBack = false;
	if (OPEN_TABLE.size() > 0){
		PTable[page].frame = OPEN_TABLE.back();
		OPEN_TABLE.pop_back();
		if (LRU){
			CLOCK_BUFFER.push_back(page);
		}
	}else{
		unsigned short victim = determineVictim(page);
		if (pageIsValid(victim) && pageIsModified(victim)){
			wroteBack = true;
		}
		PTable[victim].control = (PTable[victim].control & 0x3);
		PTable[page].frame = PTable[victim].frame;
	}

	PTable[page].control = 0x6;
	if (FIFO){
		USED_QUEUE.push(page);
	}
	return wroteBack;
}

/***********************************************************
 Name: pageIsReferenced

 Purpose: Checks R bit in Page Table at page number 'page'
 Recieves: unsigned short page
 Returns: bool
***********************************************************/
bool pageIsReferenced(unsigned short page){

	unsigned char r = ((PTable[page].control & R_MASK) >> R_SHIFT);
	if (r == 1){
		return true;
	}
	return false;

}

/***********************************************************
 Name: pageIsModified

 Purpose: Checks M bit in Page Table at page number 'page'
 Recieves: unsigned short page
 Returns: bool
***********************************************************/
bool pageIsModified(unsigned short page){

	unsigned char m = (PTable[page].control & M_MASK);
	if (m == 1){
		return true;
	}
	return false;

}

/***********************************************************
 Name: pageIsValid

 Purpose: Checks V bit in Page Table at page number 'page'
 Recieves: unsigned short page
 Returns: bool
***********************************************************/
bool pageIsValid(unsigned short page){

	unsigned char v = ((PTable[page].control & V_MASK) >> V_SHIFT);
	if (v == 1){
		return true;
	}
	return false;

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
		int lineCount = 0;
		unsigned short startFrame = 0;
		while (getline(infile,line)){
			lineCount++;
			istringstream iss(line);
			vector<string> tokens;
    		copy(istream_iterator<string>(iss), 
        			istream_iterator<string>(),
      				back_inserter(tokens));
			if (lineCount == 1){
				if (tokens[0].compare("FIFO") == 0){
					FIFO = true;
				}else{
					LRU = true;
				}
			}else if (lineCount == 2){
				frameCount = stoi(tokens[0]);
			}else if (lineCount == 3){
				startFrame = strtoul(tokens[0].c_str(),NULL,16);
				for (unsigned short i = (startFrame + frameCount - 1); i >= startFrame; i--){
					OPEN_TABLE.push_back(i);
				}
			}else{
				unsigned short address = strtoul(tokens[0].c_str(),NULL,16);
				unsigned short page = ((address & PAGE_MASK) >> PAGE_SHIFT);
				unsigned short offset = (address & OFFSET_MASK);
				char writeBack = ' ';
				char pageFault = ' ';
				if (!pageIsValid(page)){
					bool wb = processPageFault(page);
					pageFault = 'F';
					FAULT_COUNT++;
					if (wb){
						writeBack = 'B';
						WBACK_COUNT++;
					}
				}
				unsigned short frame = PTable[page].frame;
				unsigned int physicalAddress = (frame * FRAME_SIZE) + offset;

				if (tokens[1].compare("R") == 0){
					printf("%04x R %d %04x %c %c %06x\n",address,page,offset,pageFault,writeBack,physicalAddress);
					PTable[page].control = (PTable[page].control | 0x2);
					READ_COUNT++;
				}else{
					printf("%04x W %d %04x %c %c %06x\n",address,page,offset,pageFault,writeBack,physicalAddress);
					PTable[page].control = (PTable[page].control | 0x3);
					WRITE_COUNT++;
				}
				if (DEBUG_FLAG) printTable();
			}
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
				if (i+1 < argc){
					if (argv[i+1][0] == '-'){
						cout<<"No Memory Reference File Given After Flag"<<endl;
						return 0;
					}else{
						string temp(argv[i+1]);
						REF_FILE = temp;
						i++;
					}
				}else{
					cout<<"No Memory Reference File Given After Flag"<<endl;
					return 0;
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

