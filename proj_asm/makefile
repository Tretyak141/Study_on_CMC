first: main.c string.h
	gcc -m32 -c -o main.o main.c
second: string.asm
	nasm -f elf32 -o string.o string.asm
res: string.o main.o
	gcc -m32 -o res string.o main.o
run:
	./res