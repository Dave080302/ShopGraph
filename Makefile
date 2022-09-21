#!/bin/bash

build: tema3.o task1.o task2.o task3.o
	gcc -o tema3 tema3.o task1.o task2.o task3.o -g
tema3.o: tema3.c task1.h task2.h
	gcc -c tema3.c -g
task1.o: task1.c task1.h
	gcc -c task1.c -g
task2.o: task2.c task2.h
	gcc -c task2.c -g
task3.o: task3.c task3.h
	gcc -c task3.c -g
clean:
	rm -rf "tema3"
	rm -rf *.o
