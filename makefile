CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -std=c99 -pedantic
OBJ = main.o auxiliares.o entradas.o jogador.o jogo.o saco.o tabuleiro.o
DEPS = auxiliares.h entradas.h jogador.h jogo.h saco.h tabuleiro.h
VFLAGS = -v --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes
EXEC = ./scrabble palavras-validas.txt
TIMED_RUN = time ./scrabble 

all: scrabble

scrabble: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o scrabble

valgrind:
	valgrind $(VFLAGS) $(EXEC)

run:
	$(EXEC)

timed:
	$(TIMED_RUN)
