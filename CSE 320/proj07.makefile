proj07: proj07.driver.o proj07.support.o
	gcc -o proj07 proj07.driver.o proj07.support.o

proj07.driver.o: proj07.driver.c /user/cse320/Projects/project07.support.h
	gcc -Wall -c proj07.driver.c

proj07.support.o: proj07.support.c /user/cse320/Projects/project07.support.h
	gcc -Wall -c proj07.support.c

