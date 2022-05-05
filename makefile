all : COMPILATION EXECUTION

COMPILATION : graphe.c main.c tresor.c draw.c input.c init.c text.c
	gcc -Wall -o projet graphe.c main.c tresor.c draw.c input.c init.c text.c -lSDL2 -lSDL2_image -lm

EXECUTION :
	./projet