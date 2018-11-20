#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <stdio.h>

int TabelaPontos(char x);
/*Dado um char x ela retorna seu valor no jogo*/

int TabelaQuantidades(char x);
/*Dado um char x ela retorna a quantidade inicial desta letra no jogo*/

char TabelaAlfabeto(int x);
/*Dado um int x ela retorna a xzesima letra do alfabeto*/

int VerificaVeracidade(FILE *arq, char *palavra);
/*dado o arquivo de entrada arq e a string palavra, para cada linha do arquivo
testamos se a string a qual corresponde é igual a palavra, usando strcmp.
Se em algum momento for, retornamos 0, se não, retornamos -1*/

#endif
