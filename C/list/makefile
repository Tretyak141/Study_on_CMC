st: list.h list.c
	gcc -c list.c -o list.o
res: list.o main.c
	gcc main.c list.c -o res
run:
	valgrind ./res