proj10: proj10.support.o /user/cse320/Projects/project10.driver.o /user/cse320/Projects/project10.support.h
	gcc proj10.support.o /user/cse320/Projects/project10.driver.o -o proj10

proj10.support.o: proj10.support.s
	gcc -g -c proj10.support.s
