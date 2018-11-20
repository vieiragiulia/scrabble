#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"


void CriaJogador(int i, Saco *s, Jogador *j){
    j->numero = i;
    j->pontos = 0;
    j->quantidade = NUM;
    j->passa = 0;
    RetiraLetras(s, NUM, j->letras);
}


void ImprimeLetras(Jogador *j){
    printf("\nJogador %d:\n", j->numero);
    printf("\n");
    for(int i = 0; i < NUM; i++) printf("%d\t%c\n", i, j->letras[i]);
}


void SeparaLetras(Jogador *j, int *p, int n, char letras[]){
    if(n > j->quantidade) return; //se o jogador tentar tirar mais pedras do que tem, sai
    for(int i = 0; i < n; i++){
        letras[i] = j->letras[p[i]];
        j->letras[p[i]] = ' ';
        if(letras[i] == ' ') return; //se o jogador tentar acessar uma posição vazia, sai
    }
    j->quantidade -= n;
}


int RepreencheLetras(Jogador *j, Saco *s, int n){
    char *l = (char*)calloc(NUM+1, sizeof(char));
    int r = RetiraLetras(s, n, l); //retira as letras necessárias
    if(r == -1 && l[0] == 0) return -1; //se não tinha letras retorna -1
    int k = 0;
    int tam = strlen(l); //pegamos o número de letras que conseguimos retirar
    for(int i = 0; i < NUM; i++){
        if(j->letras[i] == ' ' && k < tam){
            j->letras[i] = l[k];
            k++;
        }
    }
    j->quantidade += tam;
    return 0;
}


int ContaPontos(char *letras, int n){
    int pontos = 0;
    for(int i = 0; i < n; i++){
        pontos += TabelaPontos(letras[i]);
    }
    return pontos;
}


void AumentaPontos(Jogador *j, int x){
    j->pontos += x;
}


void PassaAVez(Jogador *j, int x){
      j->passa++;
}


void TrocaPedras(Saco *s, Jogador *j, int n, int *p){
    char l[n+1];
    RetiraLetras(s, n, l);
    for(int i = 0; i < n; i++){
        j->letras[p[i]] = l[i];
    }
}


void SubtraiLixo(Jogador *j){
    int x = ContaPontos(j->letras, j->quantidade);
    j->pontos -= x;
}


void GeraVencedor(Jogador j[], int n){
    for(int i= 0; i< n; i++){
    for(int k = i+1; k < n; k++){
        if ( j[k].pontos > j[i].pontos){
            Jogador *aux = &j[k];
            j[k] = j[i];
            j[i] = *aux;
      }
    }
  }
}


void LiberaJogador(Jogador *j){
    free(j);
}
