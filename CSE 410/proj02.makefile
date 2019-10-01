proj02: proj02.student.o
	g++ -o proj02 proj02.student.o

proj02.student.o: proj02.student.c
	g++ -c proj02.student.c
