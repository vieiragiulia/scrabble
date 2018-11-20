#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "saco.h"


Saco *CriaSacoVazio(){
    Saco *s = (Saco*)calloc(1, sizeof(Saco));
    s->max = MAX;
    s->primeira = NULL;
    return s;
}


Letra *CriaLetra(char x){
    Letra *l = (Letra*)calloc(1, sizeof(Letra));
    l->nome = x;
    l->valor = TabelaPontos(x);
    l->quantidade = TabelaQuantidades(x);
    l->prox = NULL;
    return l;
}


void InsereLetra(Saco *s, char x){
      Letra *q = CriaLetra(x);
      if(s->primeira == NULL){
            s->primeira = q;
            return;
      }
      Letra *p = s->primeira;
      while(p->prox != NULL) p = p->prox;
      p->prox = q;
}

void PreencheSaco(Saco *s){
    s->quantidade = QUANT;
    char x;
    for(int i = 0; i < s->max; i++){
        x = TabelaAlfabeto(i);
        InsereLetra(s, x);
        x++;
    }
}


int RetiraLetras(Saco *s, int n, char *l){
    time_t t;
    srand(time(&t));
    for(int i = 0; i < n; i++){
        int x = rand()%23;
        Letra *aux = s->primeira;
        for(int j = 0; j < x; j++) aux = aux->prox; //chega até a letra no saco
        if(aux->quantidade > 0){ //se ainda temos a letra disponível
            l[i] = aux->nome; //insere a letra no vetor
            aux->quantidade--; //diminui um no número de pedras da letra disponíveis
            s->quantidade--;
        }
        else i--; //contamos como se a iteração não tivesse acontecido
        if(s->quantidade == 0) return -1; //se acabarem as peças retorna
    }
    return 0;
}


void LiberaSaco(Saco *s){
    Letra *p = s->primeira;
    Letra *q = p->prox;
    while(q != NULL){
        free(p);
        p = q;
        q = p->prox;
    }
    free(p);
    free(s);
}
