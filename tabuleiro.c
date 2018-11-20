#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabuleiro.h"


Tabuleiro *CriaTabuleiroVazio(){
    Tabuleiro *t = (Tabuleiro*)calloc(1, sizeof(Tabuleiro));
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            t->mesa[i][j] = ' ';
        }
    }
    return t;
}


void ImprimeTabuleiro(Tabuleiro *t){
        printf("     ");
        for(int j = 0; j < TAM - 1; j++){
            if (j < 10) printf(" %d  ", j);
            else printf("%d  ", j);
        }
        printf("\n    |");
        for(int k = 0; k < TAM - 1; k++) printf("---|");

        for(int i = 0; i < TAM - 1; i++){
            if (i < 10 ) printf("\n %d  |", i);
            else printf("\n %d |", i);

            for(int j = 0; j < TAM - 1; j++){
                printf(" %c |", t->mesa[i][j]);
            }

            printf("\n    |");
            for(int k = 0; k < TAM - 1; k++) printf("---|");
        }
        printf("\n");
}


int VerificaDisponibilidade(Tabuleiro *t, int l, int c, int s, int n){
    if(s == -1 && t->mesa[l][c] != 0) return 1;
    for(int i = 0; i < n; i++){
        if(s > -1 && s < 2){
            int aux = l;
            if(t->mesa[aux][c] != ' ') return 1;
            if (s == 0) aux--;
            else aux++;
        }
        else if (s >= 2){
            int aux = c;
            if(t->mesa[l][aux] != ' ') return 1;
            if(s == 2) aux--;
            else aux++;
        }
    }
    return 0;
}


char *ExtraiVerticalSubindo(Tabuleiro *t, char *letras, int l, int c, int n){
    char *palavra = (char*)calloc(TAM, sizeof(char)); //salva a palavra que vamos usar
    int j = 0;
    int m = 0;
    for(int i = TAM-1; i > 0; i--){
        if(i > l){//se posição abaixo da primeira modificada
            if(t->mesa[i][c] == ' '){ //e vazia
                for(int k = j; k > 0; k--) palavra[k] = ' '; //se tivermos algo salvo como palavra, apaga
                j = 0; //volta o contador do vetor palavra para zero
            }
            else palavra[j] = t->mesa[i][c]; //se não vazia, aloca o que tem
        }
        else if(i < l-n){ //se já passou da ultima modificada
            if(t->mesa[i][c] == ' ') return palavra; //e vazia retorna palavra
            else palavra[j] = t->mesa[i][c]; //e não vazia: ainda faz parte da palavra, então salva
        }
        else{//se está dentro da parte que vamos modificar
            palavra[j]  = letras[m]; //alocamos a letra na palavra
            m++;
            j++;
        }
    }
    return palavra;
}


char *ExtraiVerticalDescendo(Tabuleiro *t, char *letras, int l, int c, int n){
    char *palavra = (char*)calloc(TAM, sizeof(char)); //salva a palavra que vamos usar
        int j = 0;
        int m = 0;
        for(int i = 0;  i < TAM-1; i++){
            if(i < l){//se posição a cima da primeira modificada
                if(t->mesa[i][c] == ' '){ //e vazia
                    for(int k = j; k > 0; k--) palavra[k] = ' '; //se tivermos algo salvo como palavra, apaga
                    j = 0; //volta o contador do vetor palavra para zero
                }
                else palavra[j] = t->mesa[i][c]; //se não vazia, aloca o que tem
            }
            else if(i > l+n){ //se já passou da ultima modificada
                if(t->mesa[i][c] == ' ') return palavra; //e vazia retorna palavra
                else palavra[j] = t->mesa[i][c]; //e não vazia: ainda faz parte da palavra, então salva
            }
            else{//se está dentro da parte que vamos modificar
                palavra[j]  = letras[m]; //alocamos a letra na palavra
                m++;
                j++;
            }
        }
    return palavra;
}


char *ExtraiHorizontalDireitaEsquerda(Tabuleiro *t, char *letras, int l, int c, int n){
    char *palavra = (char*)calloc(TAM, sizeof(char)); //salva a palavra que vamos usar
        int j = 0;
        int m = 0;
        for(int i = TAM-1;  i > 0; i--){
            if(i > c){//se posição antes da primeira modificada
                if(t->mesa[l][i] == ' '){ //e vazia
                    for(int k = j; k > 0; k--) palavra[k] = ' '; //se tivermos algo salvo como palavra, apaga
                    j = 0; //volta o contador do vetor palavra para zero
                }
                else palavra[j] = t->mesa[l][i]; //se não vazia, aloca o que tem
            }
            else if(i < c-n){ //se já passou da última modificada
                if(t->mesa[l][i] == ' ') return palavra; //e vazia retorna palavra
                else palavra[j] = t->mesa[l][i]; //e não vazia: ainda faz parte da palavra, então salva
            }
            else{//se está dentro da parte que vamos modificar
                palavra[j]  = letras[m]; //alocamos a letra na palavra
                m++;
                j++;
            }
        }
    return palavra;
}


char *ExtraiHorizontalEsquerdaDireita(Tabuleiro *t, char *letras, int l, int c, int n){
    char *palavra = (char*)calloc(TAM, sizeof(char)); //salva a palavra que vamos usar
    int j = 0;
    int m = 0;
    for(int i = 0;  i < TAM-1; i++){
        if(i < c){//se posição antes da primeira modificada
            if(t->mesa[l][i] == ' '){ //e vazia
                for(int k = j; k > 0; k--) palavra[k] = ' '; //se tivermos algo salvo como palavra, apaga
                j = 0; //volta o contador do vetor palavra para zero
            }
            else palavra[j] = t->mesa[l][i]; //se não vazia, aloca o que tem
        }
        else if(i > c+n){ //se já passou da ultima modificada
            if(t->mesa[l][i] == ' ') return palavra; //e vazia retorna palavra
            else palavra[j] = t->mesa[l][i]; //e não vazia: ainda faz parte da palavra, então salva
        }
        else{//se está dentro da parte que vamos modificar
            palavra[j]  = letras[m]; //alocamos a letra na palavra
            m++;
            j++;
        }
    }
    return palavra;
}


char *ExtraiPalavra(Tabuleiro *t, char *letras, int l, int c, int s, int n){
    if(s == 0) return ExtraiVerticalSubindo(t, letras, l, c, n);
    else if(s == 1) return ExtraiVerticalDescendo(t, letras, l, c, n);
    else if(s == 2) return ExtraiHorizontalDireitaEsquerda(t, letras, l, c, n);
    else return ExtraiHorizontalEsquerdaDireita(t, letras, l, c, n);
}


void ColocaVerticalSubindo(Tabuleiro **t, char *letras, int l, int c, int n){
    int j = 0;
    for(int i = l; i > n+l; i--){
        (*t)->mesa[i][c] = letras[j];
        j++;
    }
}

void ColocaVerticalDescendo(Tabuleiro **t, char *letras, int l, int c, int n){
    int j = 0;
    for(int i = l; i < n+l; i++){
        (*t)->mesa[i][c] = letras[j];
        j++;
    }
}


void ColocaHorizontalDireitaEsquerda(Tabuleiro **t, char *letras, int l, int c, int n){
    int j = 0;
    for(int i = c; i > n+c; i--){
        (*t)->mesa[l][i] = letras[j];
        j++;
    }
}


void ColocaHorizontalEsquerdaDireita(Tabuleiro **t, char *letras, int l, int c, int n){
    int j = 0;
    for(int i = c; i < n+c; i++){
        (*t)->mesa[l][i] = letras[j];
        j++;
    }
}


void ColocaLetras(Tabuleiro **t, char *letras, int l, int c, int s, int n){
    if(s == 0) ColocaVerticalSubindo(t, letras, l, c, n);
    else if(s == 1) ColocaVerticalDescendo(t, letras, l, c, n);
    else if(s == 2) ColocaHorizontalDireitaEsquerda(t, letras, l, c, n);
    else ColocaHorizontalEsquerdaDireita(t, letras, l, c, n);
}


void LiberaTabuleiro(Tabuleiro *t){
    free(t);
}
