proj06: proj06.driver.o proj06.support.o
	gcc -o proj06 proj06.driver.o proj06.support.o

proj06.driver.o: proj06.driver.c /user/cse320/Projects/project06.support.h
	gcc -c proj06.driver.c

proj06.support.o: proj06.support.c /user/cse320/Projects/project06.support.h
	gcc -c proj06.support.c

