proj11: proj11.support.o /user/cse320/Projects/project11.driver.o /user/cse320/Projects/project11.support.h
	gcc proj11.support.o /user/cse320/Projects/project11.driver.o -o proj11

proj11.support.o: proj11.support.s
	gcc -march=native -g -c proj11.support.s
