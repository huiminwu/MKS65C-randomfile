all : main.o
	gcc -o Main main.o

main.o : main.c
	gcc -c main.c

run:
	./Main
