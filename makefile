
all: main
main: myBank.o main.o
	gcc -Wall -g -o main main.o myBank.o
main.o: main.c
	gcc -Wall -g -c main.c
myBank.o: myBank.c myBank.h
	gcc -Wall -g -c myBank.c
.PHONY: clean all
clean:
			rm -f *.o *.a *.so main
