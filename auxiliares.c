#include <stdio.h>
#include <string.h>
#include "auxiliares.h"

int TabelaPontos(char x){
    if (x == 'A') return 1;
    else if (x == 'B') return 3;
    else if (x == 'C') return 2;
    else if (x == 'D') return 2;
    else if (x == 'E') return 1;
    else if (x == 'F') return 4;
    else if (x == 'G') return 4;
    else if (x == 'H') return 4;
    else if (x == 'I') return 1;
    else if (x == 'J') return 5;
    else if (x == 'L') return 2;
    else if (x == 'M') return 1;
    else if (x == 'N') return 3;
    else if (x == 'O') return 1;
    else if (x == 'P') return 2;
    else if (x == 'Q') return 6;
    else if (x == 'R') return 1;
    else if (x == 'S') return 1;
    else if (x == 'T') return 1;
    else if (x == 'U') return 1;
    else if (x == 'V') return 4;
    else if (x == 'X') return 8;
    else if (x == 'Z') return 8;
    else return 0;

}

int TabelaQuantidades(char x){
    if (x == 'A') return 14;
    else if (x == 'B') return 3;
    else if (x == 'C') return 4;
    else if (x == 'D') return 5;
    else if (x == 'E') return 11;
    else if (x == 'F') return 2;
    else if (x == 'G') return 2;
    else if (x == 'H') return 2;
    else if (x == 'I') return 10;
    else if (x == 'J') return 2;
    else if (x == 'L') return 5;
    else if (x == 'M') return 6;
    else if (x == 'N') return 4;
    else if (x == 'O') return 10;
    else if (x == 'P') return 4;
    else if (x == 'Q') return 1;
    else if (x == 'R') return 6;
    else if (x == 'S') return 8;
    else if (x == 'T') return 5;
    else if (x == 'U') return 7;
    else if (x == 'V') return 2;
    else if (x == 'X') return 1;
    else if (x == 'Z') return 1;
    else return 3;

}

char TabelaAlfabeto(int x){
    if(x == 0) return 'A';
    else if(x == 1) return 'B';
    else if(x == 2) return 'C';
    else if(x == 3) return 'D';
    else if(x == 4) return 'E';
    else if(x == 5) return 'F';
    else if(x == 6) return 'G';
    else if(x == 7) return 'H';
    else if(x == 8) return 'I';
    else if(x == 9) return 'J';
    else if(x == 10) return 'L';
    else if(x == 11) return 'M';
    else if(x == 12) return 'N';
    else if(x == 13) return 'O';
    else if(x == 14) return 'P';
    else if(x == 15) return 'Q';
    else if(x == 16) return 'R';
    else if(x == 17) return 'S';
    else if(x == 18) return 'T';
    else if(x == 19) return 'U';
    else if(x == 20) return 'V';
    else if(x == 21) return 'X';
    else return 'Z';
}

int VerificaVeracidade(FILE *arq, char *palavra){
    char teste[21];
    while(!feof(arq)){
        fgets(teste, 20, arq);
        teste[strlen(teste) - 1] = '\0';
        if(strcmp(teste, palavra) == 0) return 0;
    }
    return -1;
}
