#ifndef JOGADOR_H
#define JOGADOR_H

#include "saco.h"

#define NUM 7

typedef struct Jogador{
    int numero; //número do jogador
    char letras[NUM]; //vetor de letras do jogador
    int quantidade; //número de letras que ele tem disponível
    int pontos; //número de pontos do jogador
    int passa; //número de vezes seguidas que ele passou a vez
}Jogador;

void CriaJogador(int i, Saco *s, Jogador *j);
/*Alocamos memória e inicializamos as variáveis do jogador
número do jogador = i
letras = vetor de letras retiradas aleatoriamente do saco
com a função RetiraLetras
quantidade = 7 -> número inicial de peças
pontos = 0
passa = 0*/

void ImprimeLetras(Jogador *j);
/*Para um jogador j imprime "Jogador i", para i = seu número
nas linhas posteriores: as letras que ele têm e sua respectiva
posição no vetor*/

int RepreencheLetras(Jogador *j, Saco *s, int n);
/*Para um jogador com n peças faltando, chama RetiraLetras
e salva n letras novas em um vetor auxiliar, depois,
insere no vetor do jogador as letras recém adquiridas
nas posições vazias.
Retorna -1 caso jogador fique sem peças
Caso contrário retorna 0*/

void SeparaLetras(Jogador *j, int *p, int n, char letras[]);
/* p guarda o número da posição das pedras que serão usadas na jogada
n guarda o número de pedras usadas
Do vetor de pedras do jogador J, separamos as n pedras definidas no vetor p,
alocando-as em um vetor auxiliar. Ao final, retornamos este vetor auxiliar*/

void PassaAVez(Jogador *j, int x);
/*se x == 1 +1 para j->passa*/

void TrocaPedras(Saco *s, Jogador *j, int n, int *p);
/*Para o jogador J, chamamos RetiraLetras e tiramos n pedras novas.
Em seguida, alocamos essas n pedras nas n posições de j->letras dadas
nas n posições de p*/

int ContaPontos(char *letras, int n);
/*Dado o vetor de letras e seu tamanho n, soma o valor tabelado de cada letra
e o retorna*/

void AumentaPontos(Jogador *j, int x);
/*incrementa a variável pontos do jogador j em x unidades*/

void SubtraiLixo(Jogador *j);
/*Chama x = ContaPontos para as letras no vetor letras de j
subtrai x de pontos*/

void GeraVencedor(Jogador j[], int n);
/*ordena o vetor com jogadores com bubble sort*/

void LiberaJogador(Jogador *j);

#endif
