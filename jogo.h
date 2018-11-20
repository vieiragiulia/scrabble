#ifndef JOGO_H
#define JOGO_H

#include "entradas.h"


void ImprimeSituacaoAtual(Tabuleiro *t, Jogador *j);
/*Chama ImprimeTabuleiro para t e ImprimeLetras para j*/

int Entrada(int p[], int *l, int *c, int *d, int *k, Jogador *j, Saco *s);
/*Chama QuerPassar, se retorna 1, retorna 1
Se não, chama QuerTrocar, se retorna 1, retorna 1
Se não, chama PegaComandos e retorna 0
Retorno 1 significa que não haverá jogada, 0 é que haverá*/

int VerificaJogada(Tabuleiro *t, int l, int c, int d, int k, char *letras, Jogador *j, int p[], char *nome);
/*Chama VerificaDisponibilidade, se return 0, return 1
Separa as letras e Extrai a palavra resultante da mesa, chamando VerificaVeracidade com essa palavra e
o arquivo de palavras válidas. Se return 1, return 1.
Se tudo ocorrer certo return 0 e podemos jogar em paz*/

int Joga(Tabuleiro **t, Saco *s, char *letras, int l, int c, int d, int k, Jogador *j, int f);
/*Chama ColocaLetras
Chama ContaPontos e AumentaPontos com o resultado
Chama RepreencheLetras
Retorna o mesmo que RepreencheLetras, pelo mesmo motivo*/

int VerificaPasses(Jogador jogadores[], int passaram[], int n);
/*Verifica se todos o jogadores passaram 2x seguidas ou mais
passaram[m] = 1 se o jogador m passou mais de uma vez seguida
passa = 1 se todos os jogadores marcaram 1 em passaram*/

void FinalizaJogo(int n, Jogador jogadores[]);
/*Chama SubtraLixo para cada um dos n jogadores em jogadores
Chama GeraVencedor
Imprime vetor*/


#endif
