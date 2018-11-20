#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"


void ImprimeSituacaoAtual(Tabuleiro *t, Jogador *j){
    ImprimeTabuleiro(t);
    ImprimeLetras(j);
}


int Entrada(int p[], int *l, int *c, int *d, int *k, Jogador *j, Saco *s){
    int r = QuerPassar(j);
    if(r == 1) return 1;
    else r = QuerTrocar(j, s);
    if(r == 1) return 1;
    else r = PegaComandos(p, l, c, d, k);
    if(r == 1) return 1;
    return 0;
}

int VerificaJogada(Tabuleiro *t, int l, int c, int d, int k, char *letras, Jogador *j, int p[], char *nome){
    int a = VerificaDisponibilidade(t, l, c, d, k);
    if(a == 1){
        printf("\nas casas que esta tentando usar nao estao disponiveis\n");
        return 0;
    }
    else{
        SeparaLetras(j, p, k, letras);
        char palavra = *ExtraiPalavra(t, letras, l, c, d, k);
        //INICIALIZA O ARQUIVO DE PALAVRAS VÁLIDAS
            FILE *arq = fopen(nome, "r");
            if(arq == NULL){
                    printf("\nARQUIVO DE VERIFICAÇÃO DE PALAVRAS INVALIDO\n");
                    return 1;
            }
        //VERIFICA SE A JOGADA PODE OCORRER
        int b = VerificaVeracidade(arq, &palavra);
        if(b != 0) return 1;
    }
    return 2;
}


int Joga(Tabuleiro **t, Saco *s, char *letras, int l, int c, int d, int k, Jogador *j, int f){
    ColocaLetras(t, letras, l, c, d, k);
    //MEXE COM OS PONTOS
    if(f == 2){
        int pontos = ContaPontos(letras, k);
        AumentaPontos(j, pontos);
    }
    //DEIXA TUDO PRONTO PARA A PRÓXIMA VEZ
    int r = RepreencheLetras(j, s, k);
    return r;
}


int VerificaPasses(Jogador jogadores[], int passaram[], int n){
    for(int m = 0; m < n; m++) if(jogadores[m].passa > 2) passaram[m] = 1;
    int aux = 0;
    for(int w = 0; w < n; w++) if(passaram[w] == 1) aux++;
    if(aux == n-1) return 1;
    return 0;
}


void FinalizaJogo(int n, Jogador jogadores[]){
    //SUBTRAI O VALOR DAS LETRAS AINDA NO VETOR DE CADA JOGADOR
    for(int i = 0; i < n; i++) SubtraiLixo(&jogadores[i]);
    //ORDENA O VETOR E GERA O VENCEDOR
    GeraVencedor(jogadores, n);
    //IMPRIME RANKING
    for(int i = 0; i < n; i++) printf("\n%d\tJogador: %d", i, jogadores[i].numero);
}
