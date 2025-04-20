timeProgram: time.o timeActions.o
	gcc -g -ansi time.o timeActions.o -o timeProgram -lm

time.o: time.c time.h
	gcc -c -Wall -ansi -pedantic time.c -o time.o

timeActions.o: timeActions.c time.h
	gcc -c -Wall -ansi -pedantic timeActions.c -o timeActions.o


