proj12: proj12.driver.o proj12.support.o
	gcc -o proj12 proj12.driver.o proj12.support.o

proj12.driver.o: proj12.driver.c /user/cse320/Projects/project12.support.h
	gcc -c proj12.driver.c

proj06.support.o: proj12.support.c /user/cse320/Projects/project12.support.h
	gcc -c proj06.support.c

