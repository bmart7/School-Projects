proj05: proj05.driver.o proj05.support.o
	gcc -o proj05 proj05.driver.o proj05.support.o -lm

proj05.driver.o: proj05.driver.c /user/cse320/Projects/project05.support.h
	gcc -c proj05.driver.c -lm

proj05.support.o: proj05.support.c /user/cse320/Projects/project05.support.h
	gcc -c proj05.support.c -lm

