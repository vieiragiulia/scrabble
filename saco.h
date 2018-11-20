#ifndef SACO_H
#define SACO_H

#include "auxiliares.h"

#define MAX 23
#define QUANT 120

typedef struct Letra{
    char nome; //qual letra é
    int quantidade; //quantas letras dessa ainda temos
    int valor; //quantos pontos essa letra vale
    struct Letra *prox;
}Letra;

typedef struct Saco{
    int quantidade; //número de pedras possível
    int max; //número de letras possível
    Letra *primeira;
}Saco;


Saco *CriaSacoVazio();
/*Alocamos memória para a lista e atribui a saco->max o número máximo de letras,
que é 23 neste jogo*/

Letra *CriaLetra(char x);
/*Aloca memória para a letra, busca o número tabelado da quantidade e valor da letra
e os aloca em suas respectivas variáveis e guarda o nome x da letra*/

void InsereLetra(Saco *s, char x);
/*Para o saco s e o char x chamamos CriaLetra para x, criando uma célula da lista.
Em seguida alocamos a célula ao final da lista*/

void PreencheSaco(Saco *s);
/*Preenchemos a lista de acordo com as especificações dadas.
Alocamos a quantidade total de pedras para 120 e, 23x, chamamos
TabelaAlfabeto para pegar a iésima letra do alfabeto e em seguida,
chamamos InsereLetra para colocá-la na lista*/

int RetiraLetras(Saco *s, int n, char *l);
/*Por n vezes: Geramos um número aleatório x de 0 a 23 usando a função rand.
Em seguida percorremos o saco s em x posições e, se nesta célula ainda houverem
letras, salvamos o nome da letra no vetor l e decrescemos em uma unidade a
quantidade de letras do saco e da célula.
Caso a letra já esteja indisponível, decrescemos o contador i de uma unidade
para fazer como se não tivéssemos tentado aquela letra.
Caso, além disso, a quantidade de letras do saco inteiro tenha acabado,
sinalizamos retornando -1 e paramos as operações. Caso não, apenas voltamos ao
loop e tentamos uma nova letra.
Se tudo terminar sem esvaziar o saco retornamos zero*/

void LiberaSaco(Saco *s);

#endif
