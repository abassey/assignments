main: memcheck.o memcheck.h
	gcc -ansi -Wall -pedantic -include memcheck.h memcheck.o main.c -o main

memcheck.o: memcheck.c
	gcc -Wall -pedantic -c memcheck.c -o memcheck.o
