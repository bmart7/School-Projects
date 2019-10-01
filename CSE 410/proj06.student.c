/***********************************************************
 Brian Martin (A56350138)
 Project #6
***********************************************************/

#include <iostream>
#include <stdexcept>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <iomanip>
#include <semaphore.h>

using namespace std;

int collectArgs(const int& argc, char* argv[]);
int collectAccounts();
void *producerThread(void* str);
void *consumerThread(void* str);
bool accountExists(int account);
void logFail(ofstream& outFile, int thread, string type, int account, double amount, string message);
void logSuccess(ofstream& outFile, int thread, string type, int account, double amount, double balance);
void printToFile();

struct record{
	int account;
	string type;
	double amount;
	int thread;
};

sem_t S;
sem_t N;
sem_t E;
int in = 0;
int out = 0;
int activeThreads = 0;
int occupied = 0;

struct record buffer[20];
vector<pair<int,double>> accountList;

const string INPUT_FILE = "accounts.old";
const string OUTPUT_FILE = "accounts.new";
const string LOG_FILE = "accounts.log";
const string PROD_FILE_HEAD = "trans";
const int threadArgs[10] = {0,1,2,3,4,5,6,7,8,9};
int THREAD_COUNT = 1;
int BUFFER_SIZE = 5;

/***********************************************************
 Name: main

 Purpose: Emulates banking system transactions from files
 Recieves: Command line argument flags for buffer size 
	and thread count
 Returns: Boolean success or fail
***********************************************************/
int main(int argc, char* argv[]){

	int success = collectArgs(argc, argv);
	if (!success) return 0;

	sem_init(&S,0,1);
	sem_init(&N,0,0);
	sem_init(&E,0,BUFFER_SIZE);

	success = collectAccounts();
	if (!success) return 0;

	vector<pthread_t> threadList;
	for (int i=0; i<THREAD_COUNT;i++){
		pthread_t temp;
		threadList.push_back(temp);
		pthread_create(&(threadList[i]),NULL,producerThread,(void*) &(threadArgs[i]));
	}

	pthread_t consumer;
	pthread_create(&consumer,NULL,consumerThread,NULL);

	for (int i=0; i<threadList.size();i++){
		pthread_join(threadList[i],NULL);
	}

	pthread_join(consumer,NULL);

	printToFile();

}

/***********************************************************
 Name: producerThread

 Purpose: Function for Producer Thread creation
 Recieves: Integer value of thread number
 Returns: None
***********************************************************/
void *producerThread(void* str){
	activeThreads++;
	int *temp;
	temp = (int*) str;
	int threadNum = *temp;
	const string filename = PROD_FILE_HEAD + to_string(threadNum);
	ifstream infile(filename);
	if (infile){
		string line;
		while (getline(infile,line)){
			istringstream iss(line);
			vector<string> tokens;
    		copy(istream_iterator<string>(iss), 
        			istream_iterator<string>(),
      				back_inserter(tokens));
			struct record temp;
			temp.account = stoi(tokens[0]);
			temp.type = tokens[1];
			temp.amount = stod(tokens[2]);
			temp.thread = threadNum;

			sem_wait(&E);
			sem_wait(&S);
			buffer[in] = temp;
			in = (in+1) % BUFFER_SIZE;
			occupied++;
			sem_post(&S);
			sem_post(&N);

		}
	}else{
		cout<<"Thread "<<threadNum<<": Unable to access file --> "<<filename<<endl;
	}
	activeThreads--;
	pthread_exit(NULL);
}

/***********************************************************
 Name: consumerThread

 Purpose: Function for Consumer Thread creation
 Recieves: None
 Returns: None
***********************************************************/
void *consumerThread(void* str){
	ofstream outFile;
	outFile.open(LOG_FILE, ios_base::trunc);
	
	while (occupied > 0 || activeThreads > 0){

		sem_wait(&N);
		sem_wait(&S);
		struct record temp = buffer[out];
		out = (out+1) % BUFFER_SIZE;
		occupied--;
		sem_post(&S);
		sem_post(&E);

		if (temp.type.compare("open")==0){
			if (accountExists(temp.account)){
				logFail(outFile,temp.thread,temp.type,temp.account,temp.amount,"Account Already Exists");
			}else if (temp.amount >= 0){
				accountList.push_back(make_pair(temp.account,temp.amount));
				logSuccess(outFile,temp.thread,temp.type,temp.account,temp.amount,temp.amount);
			}else{
				logFail(outFile,temp.thread,temp.type,temp.account,temp.amount,"Negative Amount");
			}
		}else if (temp.type.compare("deposit")==0){
			if (accountExists(temp.account)){
				if (temp.amount >= 0){
					for (int i=0;i<accountList.size();i++){
						if (accountList[i].first == temp.account){
							accountList[i].second += temp.amount;
							logSuccess(outFile,temp.thread,temp.type,temp.account,
										temp.amount,accountList[i].second);
							break;
						}
					}
				}else{
					logFail(outFile,temp.thread,temp.type,temp.account,temp.amount,"Negative Amount");
				}
			}else{
				logFail(outFile,temp.thread,temp.type,temp.account,temp.amount,"Account Doesn't Exist");
			}
		}else{
			if (accountExists(temp.account)){
				if (temp.amount >= 0){
					for (int i=0;i<accountList.size();i++){
						if (accountList[i].first == temp.account){
							if (accountList[i].second >= temp.amount){
								accountList[i].second -= temp.amount;
								logSuccess(outFile,temp.thread,temp.type,temp.account,
										temp.amount,accountList[i].second);
								break;
							}else{
								logFail(outFile,temp.thread,temp.type,temp.account,
										temp.amount,"Insufficient Funds");
							}
						}
					}
				}else{
					logFail(outFile,temp.thread,temp.type,temp.account,temp.amount,"Negative Amount");
				}
			}else{
				logFail(outFile,temp.thread,temp.type,temp.account,temp.amount,"Account Doesn't Exist");
			}
		}
	}
	outFile.close();
	pthread_exit(NULL);
}

/***********************************************************
 Name: printToFile

 Purpose: Prints ending list of bank accounts and balances
 Recieves: None
 Returns: None
***********************************************************/
void printToFile(){
	ofstream outFile;
	outFile.open(OUTPUT_FILE, ios_base::trunc);
	for (int i=0; i<accountList.size(); i++){
		outFile<<setw(6)<<setfill('0')<<accountList[i].first<<" "<<accountList[i].second<<endl;
	}
	outFile.close();
}

/***********************************************************
 Name: logSuccess

 Purpose: Prints values to formatted success log to file
 Recieves: Account infomation to be formatted
 Returns: None
***********************************************************/
void logSuccess(ofstream& outFile, int thread, string type, int account, double amount, double balance){
	outFile<<"[In Thread "<<thread<<"] Transaction \""<<type<<"\" on Account \""<<
			setw(6)<<setfill('0')<<account<<"\" Succeeded\n\t--Amount: $"<<amount<<"\tCurrent Balance: $"
			<<balance<<endl<<endl;
}

/***********************************************************
 Name: logFail

 Purpose: Prints values to formatted failure log to file
 Recieves: Account infomation to be formatted
 Returns: None
***********************************************************/
void logFail(ofstream& outFile, int thread, string type, int account, double amount, string message){
	outFile<<"[In Thread "<<thread<<"] Transaction \""<<type<<"\" on Account \""<<
		setw(6)<<setfill('0')<<account<<"\" of Amount $"<< amount<<" Failed\n\t--"<<message<<endl<<endl;
}

/***********************************************************
 Name: accountExists

 Purpose: Checks account list for matching account numbwers
 Recieves: Account number
 Returns: bool exists or not
***********************************************************/
bool accountExists(int account){
	for (int i=0;i<accountList.size();i++){
		if (accountList[i].first == account){
			return true;
		}
	}
	return false;
}

/***********************************************************
 Name: collectAccounts

 Purpose: Reads bank account information from input file
 Recieves: None
 Returns: Integer success value
***********************************************************/
int collectAccounts(){
	ifstream infile(INPUT_FILE);
	if (infile){
		string line;
		while (getline(infile,line)){
			istringstream iss(line);
    		vector<string> tokens;
    		copy(istream_iterator<string>(iss), 
        			istream_iterator<string>(),
      				back_inserter(tokens));
			accountList.push_back(make_pair(stoi(tokens[0]), stod(tokens[1])));
		}
	}else{
		cout<<"Could Not Read Input File: "<<INPUT_FILE<<endl;
		return 0;
	}
	return 1;
}

/***********************************************************
 Name: collectAccounts

 Purpose: Reads flag information from command line arguments
 Recieves: Main function input
 Returns: Integer success value
***********************************************************/
int collectArgs(const int& argc, char* argv[]){
	for (int i=1; i<argc; i++){
		if (argv[i][0] == '-' && strlen(argv[1]) > 1){
			if (argv[i][1] == 'p'){
				if (strlen(argv[i]) == 2){
					if (argc >= i+2){
						try{
							int temp = stoi(argv[i+1]);
							if (temp > 10){
								cout<<"Invalid Arguments: Thread Count Too Large"<<endl;
								return 0;
							}
							THREAD_COUNT = temp;
							i++;
						}catch (invalid_argument e){
							cout<<"Invalid Arguments: Thread Count"<<endl;
							return 0;
						}
					}else{
						cout<<"Invalid Arguments: No Thread Count Provided With Flag"<<endl;
						return 0;
					}
				}else{
					string token(argv[i]);
					token = token.substr(2);
					try{
						int temp = stoi(token);
						if (temp > 10){
							cout<<"Invalid Arguments: Thread Count Too Large"<<endl;
							return 0;
						}
						THREAD_COUNT = temp;
					}catch (invalid_argument e){
						cout<<"Invalid Arguments: Invalid Flag ==> \""<<argv[i]<<"\""<<endl;
						return 0;
					}
				}
			}else if (argv[i][1] == 'b'){
				if (strlen(argv[i]) == 2){
					if (argc >= i+2){
						try{
							int temp = stoi(argv[i+1]);
							if (temp > 20){
								cout<<"Invalid Arguments: Buffer Size Too Large"<<endl;
								return 0;
							}
							BUFFER_SIZE = temp;
							i++;
						}catch (invalid_argument e){
							cout<<"Invalid Arguments: Buffer Size"<<endl;
							return 0;
						}
					}else{
						cout<<"Invalid Arguments: No Buffer Count Provided With Flag"<<endl;
						return 0;
					}
				}else{
					string token(argv[i]);
					token = token.substr(2);
					try{
						int temp = stoi(token);
						if (temp > 20){
							cout<<"Invalid Arguments: Buffer Size Too Large"<<endl;
							return 0;
						}
						BUFFER_SIZE = temp;
					}catch (invalid_argument e){
						cout<<"Invalid Arguments: Invalid Flag ==> \""<<argv[i]<<"\""<<endl;
						return 0;
					}
				}
			}else{
				cout<<"Invalid Arguments: Invalid Flag ==> \""<<argv[i]<<"\""<<endl;
				return 0;
			}
		}else{
			cout<<"Invalid Arguments: Invalid Flag ==> \""<<argv[i]<<"\""<<endl;
			return 0;
		}
	}
	return 1;
}
