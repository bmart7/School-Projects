proj08: proj08.main.o
	gcc proj08.main.o -o proj08

proj08.main.o: proj08.main.s
	gcc -c proj08.main.s -o proj08.main.o

