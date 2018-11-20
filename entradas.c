#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entradas.h"

int QuerPassar( Jogador *j){
    printf("Voce quer passar a vez? Se sim digite 1, se não digite 0\t");
    int passaAgora;
    scanf("%d", &passaAgora);
    if(passaAgora == 1){
        PassaAVez(j, passaAgora);
        return 1;
    }
    else j->passa = 0;
    return 0;
}


int QuerTrocar(Jogador *j, Saco *s){
    printf("Voce quer trocar alguma peca? Se sim digite 1, se nao digite 0\t");
    int w;
    scanf("%d", &w);
    if(w == 1){
        printf("Quantas pecas quer mudar? Pode ser 1 ou 2\t");
        int n;
        scanf("%d", &n);
        if(n > 2) return 1;
        printf("Qual o numero das pecas quer mudar?\t");
        int v[n+1];
        for(int i = 0; i < n; i++) scanf("%d", &v[i]);
        char lixo[n+1];
        SeparaLetras(j, v, n, lixo);
        RepreencheLetras(j, s, n);
        ImprimeLetras(j);
        return 1;
    }
    return 0;
}


int PegaComandos(int p[], int *l, int *c, int *d, int *k){
    printf("Digite a posicao correspondente as letras que quer usar:\t");
    char q[2*NUM+1];
    const char cut[2] = " ";
    scanf("\n%[^\n]", q);
    *k = 0;
    char *token = strtok(q, cut);
    while(token != NULL){
        p[*k] = atoi(token);
        token = strtok(NULL, cut);
        (*k)++;
    }
    (*k)++;
    printf("Digite a linha, coluna e direcao que quer inserir as letras:\n----\n 0 = para cima\n 1 = para baixo\n 2 = para tras\n 3 = para frente\n 4 = nenhum\n----\n");
    scanf("%d", l);
    scanf("%d", c);
    scanf("%d", d);
    if(*d < 0 || *d > 4){
        printf("Sentido indisponiviel");
        return 1;
    }
    return 0;
}
