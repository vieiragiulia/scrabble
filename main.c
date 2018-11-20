#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jogo.h"


int main(int argc, char* argv[]){
        //INICIALIZA COISAS DO JOGO
        int n = 0;
        Saco *s = CriaSacoVazio();
        PreencheSaco(s);
        Tabuleiro *t = CriaTabuleiroVazio();
        printf("\nInsira o numero de jogadores: ");
        scanf("%d", &n);
        Jogador *jogadores = (Jogador*)calloc(n+1, sizeof(Jogador));
        for(int i = 0; i < n; i++) CriaJogador(i, s, &jogadores[i]);
        //NÚMERO DO JOGADOR
        int j = 0;
        //VARIÁVEIS QUE GUARDAM CRITÉRIOS DE PARADA
        int zerou = 0; //vira 1 se alguém zerar suas peças
        int passa = 0; //vira 1 se todos passarem a vez 2 vezes seguidas
        int *passaram = (int*)calloc(n+1, sizeof(int)); //salva quais jogadores já passaram mais de 1x seguida
        //VARIÁVEIS QUE GUARDAM ENTRADAS
        int *p = (int*)calloc(NUM+1, sizeof(int)); //vetor que guarda as posições das letras usadas
        int k = 0; //numero de posiçoes reais de p
        int l = 0; //linha
        int c = 0; //coluna
        int d = 0; //direção
        char *letras = (char*)calloc(NUM+1, sizeof(char)); //letras a serem usadas
        //JOGO
        while(zerou != 1 && passa != 1){
                j %= n;
                //PARTE VISUAL INICIAL
                ImprimeSituacaoAtual(t, &jogadores[j]);
                //PEGA AS ENTRADAS DO JOGADOR
                int e = Entrada(p, &l, &c, &d, &k, &jogadores[j], s);
                //SE O JOGADOR QUISER JOGAR, JOGAMOS
                if(e == 0){
                        //VERIFICA A POSSIBILIDADE DA JOGADA
                        int f = VerificaJogada(t, l, c, d, k, letras, &jogadores[j], p, argv[1]);
                        //SE ESTIVER TUDO CERTO, JOGA
                        if(f > 0){
                                int g = Joga(&t, s, letras, l, c, d, k, &jogadores[j], f);
                                //SE O JOGADOR TERMINOU A JOGADA VAZIO, ZEROU = 1
                                if(g == -1) zerou = 1;
                        }
                }
                //VERIFICA SE PASSARAM A VEZ
                passa = VerificaPasses(jogadores, passaram, n);
                //PRÓXIMO JOGADOR
                j++;
        }
        //FINALIZA A CONTAGEM DOS PONTOS ETC
        FinalizaJogo(n, jogadores);
        //LIBERA AS MEMÓRIAS
        LiberaTabuleiro(t);
        LiberaSaco(s);
        free(jogadores);
        free(passaram);
        free(letras);
        free(p);
        //Libera(t, s, jogadores, n, passaram);
        return 0;
}
