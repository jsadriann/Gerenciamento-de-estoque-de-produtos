#compilação do projeto

CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=-lpq

all: main

main: main.o
	$(CC) main.o $(LDFLAGS) -o main -std=c++11
main.o: controller/main.cpp
	$(CC) $(CFLAGS) controller/main.cpp -o main.o

clean:
	rm -f *.o main
