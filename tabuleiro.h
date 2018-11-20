#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "auxiliares.h"

#define TAM 16
#define AUX 20

typedef struct Tabuleiro{
    char mesa[TAM][TAM]; //matriz do tabuleiro
}Tabuleiro;


Tabuleiro *CriaTabuleiroVazio();
/*Gera-se uma matriz de chars 15 x 15
1. Aloca momória para o tabuleiro t
2. Com 2 for, aloca ' ' como elemento de todas as casas do Tabuleiro
retorna o Tabuleiro t vazio assim*/

void ImprimeTabuleiro(Tabuleiro *t);


int VerificaDisponibilidade(Tabuleiro *t, int l, int c, int s, int n);
/*Verifica se as casas requeridas para a jogada estão disponíveis
Retorna 1 se sim e 0 se não.
Caso o sinal s do sentido de colocação das pedras seja -1 e a posição (l,c)
esteja vazia, retornamos 1.
Caso s seja outro número válido, ou seja, trabalharemos com mais de uma peça,
entramos em um for de 0 a n, para n = número de peças a serem colocadas.
Se o sinal indicar verticalidade (ou seja, 0 < s < 2), para aux inicialmente = l,
verificamos a casa (aux,c), se esta estiver preenchida retornamos 1, se não,
caso estejamos subindo aux--, ou se estivermos descendo, aux++.
Similarmente ocorre para a horizontalidade, com os condicionais correspondentes.
1 < s < 4, aux inicialmente = c, verificamos (l, aux), indo para trás com aux--
e para frente com aux++ e retornando 1 caso em algum momento a casa esteja
preenchida.
Se a jogada sobreviver sem retornar 1, retornamos 0, ou seja, casas disponiveis.*/


char *ExtraiVerticalSubindo(Tabuleiro *t, char *letras, int l, int c, int n);
/*Esta função extrai do tabuleiro a palavra que será formada a partir da alocação
das n letras presentes em *letras, começando de (l,c) para cima.
Alocamos essa resposta no vetor palavra.
avaliamos para cada posição do vetor t->mesa[][c] e:
1. caso estivermos antes da posição final de se alocar letras novas:
1.1. se o tabuleiro tiver casa vazia e palavra tiver algo alocado, apagamos tudo.
Porque isso significa que quaisquer letras anteriores a esta não fazem parte
da palavra que devemos avaliar.
1.2. se o tabuleiro tiver casa cheia palavra recebe a letra ali alocada, porque
pode ser que ela faça parte da palavra final.
 2. caso estivermos depois da posição inicial de se alocar letras novas:
 2.1. se a casa for vazia, retornamos a palavra, porque a palavra final
 acabou neste momento
 2.2. se não, guardamos a letra alocada nesta casa em palavra, porque ela
 pode fazer parte da palavra final
 3. caso estivermos no conjunto em que devem ser alocadas as letras novas
 alocamos em palavra as letras de letras*/

char *ExtraiVerticalDescendo(Tabuleiro *t, char *letras, int l, int c, int n);
/*Esta função extrai do tabuleiro a palavra que será formada a partir da alocação
das n letras presentes em *letras, começando de (l,c) para baixo.
Alocamos essa resposta no vetor palavra.
avaliamos para cada posição do vetor t->mesa[][c] e:
1. caso estivermos antes da posição inicial de se alocar letras novas:
1.1. se o tabuleiro tiver casa vazia e palavra tiver algo alocado, apagamos tudo.
Porque isso significa que quaisquer letras anteriores a esta não fazem parte
da palavra que devemos avaliar.
1.2. se o tabuleiro tiver casa cheia palavra recebe a letra ali alocada, porque
pode ser que ela faça parte da palavra final.
 2. caso estivermos depois da posição inicial de se alocar letras novas:
 2.1. se a casa for vazia, retornamos a palavra, porque a palavra final
 acabou neste momento
 2.2. se não, guardamos a letra alocada nesta casa em palavra, porque ela
 pode fazer parte da palavra final
 3. caso estivermos no conjunto em que devem ser alocadas as letras novas
 alocamos em palavra as letras de letras*/

char *ExtraiHorizontalDireitaEsquerda(Tabuleiro *t, char *letras, int l, int c, int n);
/*Esta função extrai do tabuleiro a palavra que será formada a partir da alocação
das n letras presentes em *letras, começando de (l,c) para esquerda.
Alocamos essa resposta no vetor palavra.
avaliamos para cada posição do vetor t->mesa[][c] e:
1. caso estivermos antes da posição final de se alocar letras novas:
1.1. se o tabuleiro tiver casa vazia e palavra tiver algo alocado, apagamos tudo.
Porque isso significa que quaisquer letras anteriores a esta não fazem parte
da palavra que devemos avaliar.
1.2. se o tabuleiro tiver casa cheia palavra recebe a letra ali alocada, porque
pode ser que ela faça parte da palavra final.
 2. caso estivermos depois da posição inicial de se alocar letras novas:
 2.1. se a casa for vazia, retornamos a palavra, porque a palavra final
 acabou neste momento
 2.2. se não, guardamos a letra alocada nesta casa em palavra, porque ela
 pode fazer parte da palavra final
 3. caso estivermos no conjunto em que devem ser alocadas as letras novas
 alocamos em palavra as letras de letras*/

char *ExtraiHorizontalEsquerdaDireita(Tabuleiro *t, char *letras, int l, int c, int n);
/*Esta função extrai do tabuleiro a palavra que será formada a partir da alocação
das n letras presentes em *letras, começando de (l,c) para direita.
Alocamos essa resposta no vetor palavra.
avaliamos para cada posição do vetor t->mesa[][c] e:
1. caso estivermos antes da posição inicial de se alocar letras novas:
1.1. se o tabuleiro tiver casa vazia e palavra tiver algo alocado, apagamos tudo.
Porque isso significa que quaisquer letras anteriores a esta não fazem parte
da palavra que devemos avaliar.
1.2. se o tabuleiro tiver casa cheia palavra recebe a letra ali alocada, porque
pode ser que ela faça parte da palavra final.
 2. caso estivermos antes da posição inicial de se alocar letras novas:
 2.1. se a casa for vazia, retornamos a palavra, porque a palavra final
 acabou neste momento
 2.2. se não, guardamos a letra alocada nesta casa em palavra, porque ela
 pode fazer parte da palavra final
 3. caso estivermos no conjunto em que devem ser alocadas as letras novas
 alocamos em palavra as letras de letras*/

char *ExtraiPalavra(Tabuleiro *t, char *letras, int l, int c, int s, int n);
/*Se o sinal de sentido s for = 0 = para cima chama ExtraiVerticalSubindo
Se o sinal de sentido s for = 1 = para baixo chama ExtraiVerticalDescendo
Se o sinal de sentido s for = 2 = para cima chama ExtraiHorizontalDireitaEsquerda
Se o sinal de sentido s for = 3 = para cima chama ExtraiHorizontalEsquerdaDireita*/

void ColocaVerticalSubindo(Tabuleiro **t, char *letras, int l, int c, int n);
/*dado o tabuleiro t, o vetor de letras letras, de tamanho n: começando da
posição (l,c) alocamos t->mesa[i][c] = letras[j], para i (decrescendo) e j
(crescendo) contadores.*/

void ColocaVerticalDescendo(Tabuleiro **t, char *letras, int l, int c, int n);
/*dado o tabuleiro t, o vetor de letras letras, de tamanho n: começando da
posição (l,c) alocamos t->mesa[i][c] = letras[j], para i (crescendo) e j
(crescendo) contadores.*/

void ColocaHorizontalDireitaEsquerda(Tabuleiro **t, char *letras, int l, int c, int n);
/*dado o tabuleiro t, o vetor de letras letras, de tamanho n: começando da
posição (l,c) alocamos t->mesa[l][i] = letras[j], para i (decrescendo) e j
(crescendo) contadores.*/

void ColocaHorizontalEsquerdaDireita(Tabuleiro **t, char *letras, int l, int c, int n);
/*dado o tabuleiro t, o vetor de letras letras, de tamanho n: começando da
posição (l,c) alocamos t->mesa[l][i] = letras[j], para i (crescendo) e j
(crescendo) contadores.*/

void ColocaLetras(Tabuleiro **t, char *letras, int l, int c, int s, int n);
/*Se o sinal de sentido s for = 0 = para cima chama ColocaVerticalSubindo
Se o sinal de sentido s for = 1 = para baixo chama ColocaVerticalDescendo
Se o sinal de sentido s for = 2 = para cima chama ColocaHorizontalDireitaEsquerda
Se o sinal de sentido s for = 3 = para cima chama ColocaHorizontalEsquerdaDireita*/

void LiberaTabuleiro(Tabuleiro *t);

#endif
