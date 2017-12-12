start:finish.out
	./finish.out

CLINK=-lm
CPPFLAGS = --std=c++11 -Wall
CC=g++

finish.out:program.o krzyzowka.o
	$(CC) -o finish.out  $(CLINK) program.o krzyzowka.o

program.o: program.cpp krzyzowka.h
	$(CC) -c program.cpp $(CPPFLAGS)

krzyzowka.o: krzyzowka.cpp krzyzowka.h
	$(CC) -c krzyzowka.cpp $(CPPFLAGS)

clean:
	- rm *.o
	- rm tests_bin
