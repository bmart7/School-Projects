proj08: proj08.student.o
	g++ -o proj08 proj08.student.o

proj08.student.o: proj08.student.c
	g++ -c proj08.student.c
