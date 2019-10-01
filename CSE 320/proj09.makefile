proj09: proj09.driver.o proj09.support.o
	gcc proj09.support.o proj09.driver.o -o proj09

proj09.driver.o: proj09.driver.c /user/cse320/Projects/project09.support.h
	gcc -c proj09.driver.c

proj09.support.o: proj09.support.s
	gcc -march=native -c proj09.support.s
