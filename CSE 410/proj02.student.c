/***********************************************************
 Brian Martin (A56350138)
 Project #2
***********************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/***********************************************************
 Name: main

 Purpose: Moves contents of one file to another using buffer
 Recieves: Command line arguments consisting of file names and flags
 Returns: Boolean success or fail
***********************************************************/

int main(int argc, char* argv[]){

	char* files[2];
	int filecount = 0;
	int buffersize = 256;
	bool bflag = false;
	bool m = false;
	bool t = true;

	for (int i = 1; i < argc; i++){
		if (argv[i][0] != '-'){
			if (bflag == true){
				buffersize = 1 << atoi(argv[i]);
				bflag = false;
			}
			else if (filecount < 2){
				files[filecount] = argv[i];
				filecount++;
			}
			else{
				printf("Too Many File Names Provided\n");
				return 0;
			}
		}
		else{
			if (bflag == true){
				printf("Buffer Size Not Provided\n");
				return 0;
			}
			else if (argv[i][1] == 'b'
				&& strlen(argv[i]) == 2){
				bflag = true;
			}
			else if (argv[i][1] == 'm'
				&& strlen(argv[i]) == 2){
				m = true;
			}
			else if (argv[i][1] == 't'
				&& strlen(argv[i]) == 2){
				t = true;
			}
			else if (argv[i][1] == 'n'
				&& strlen(argv[i]) == 3){
				if (argv[i][2] == 'm'){
					m = false;
				}
				else if (argv[i][2] == 't'){
					t = false;
				}
			}
			else{
				printf("Invalid Flag\n");
				return 0;
			}
		}
	}

	if (filecount < 2){
		printf("Not Enough File Names Provided\n");
		return 0;
	}
	else if (m == false){
		printf("Not Modify Flag Set");
		return 0;
	}
	else{
		int readFd = open(files[0], O_RDONLY, S_IRUSR | S_IWUSR);
		if (readFd < 0){
			printf("Invalid Read File Path");
			return 0;
		}
		int writeFd;
		if (t == true){
			writeFd = open(files[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		}
		else{
			writeFd = open(files[1], O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
		}

		if (writeFd < 0){
			printf("Error Occurred With Write File Path");
			return 0;
		}

		char buffer[buffersize];
		int in;
		while ((in = read(readFd, &buffer, buffersize)) > 0){
			int out = write(writeFd, &buffer, in);
		}

		if (in == -1){
			printf("Error Reading File");
			return 0;
		}

		close(readFd);
		close(writeFd);
		return 1;

	}


}
