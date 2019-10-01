proj10: proj10.student.o
	g++ -o proj10 proj10.student.o

proj10.student.o: proj10.student.c
	g++ -c proj10.student.c
