#ifndef ENTRADA_H
#define ENTRADA_H

#include "tabuleiro.h"
#include "saco.h"
#include "jogador.h"

int QuerPassar( Jogador *j);
/*Verifica se o jogador quer passar a vez
Se sim, j->passa++ e return 1
Se não j->passa = 0 e return = 0*/

int QuerTrocar(Jogador *j, Saco *s);
/*Verifica se o jogador quer trocar peças
Se sim: pega quantas peças, aloca suas posições em um vetor auxiliar
Retira as peças do conjunto atual do jogador e Coloca novas no lugar*/

int PegaComandos(int p[], int *l, int *c, int *d, int *k);
/*Pega as entradas do jogador
l = linha, c = coluna, d = sinal, p = letras a serem usadas k = tamanho de p*/

#endif
