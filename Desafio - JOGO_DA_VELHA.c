//JOGO DA VELHA EM C (COM MATRIZ)
#include <stdio.h>
#include <stdlib.h>

void tabuleiro(char casas2[3][3]){
    system("cls");
    printf("\t %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", casas2[2][0], casas2[2][1], casas2[2][2]);

}

int main(){
    char casas[3][3] /*= {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'}, }*/;


    char res;
    int contJogadas,line,column, vez = 0, i, j;
    do{
        contJogadas = 1;
        for(i = 0; i <= 2;i++){
            for(j = 0; j <= 2; j++){
                casas[i][j] = ' ';
            }
        }
        do{
              tabuleiro(casas);
              if(vez % 2 == 0){
                printf("Jogador X\n");
              }else{
                printf("Jogador O\n");
              }
              printf("\nDigite a linha: ");
              scanf("%i", &line);
              printf("Digite a coluna: ");
              scanf("%i", &column);
              if(line < 1 || column < 1 || line > 3 || column > 3){
                line = 0;
                column = 0;
              }else if(casas[line-1][column-1] != ' '){
                line = 0;
                column = 0;
              }else{
                if(vez % 2 == 0){
                    casas[line-1][column-1] = 'X';
                }else{
                    casas[line-1][column-1] = 'O';
                }
                vez++;
                contJogadas++;
              }
              if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){contJogadas = 11;}
              if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){contJogadas = 11;}
              if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){contJogadas = 11;}
              if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){contJogadas = 11;}
              if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){contJogadas = 11;}
              if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){contJogadas = 11;}
              if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){contJogadas = 11;}
              if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){contJogadas = 11;}

              if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){contJogadas = 12;}
              if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){contJogadas = 12;}
              if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){contJogadas = 12;}
              if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){contJogadas = 12;}
              if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){contJogadas = 12;}
              if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){contJogadas = 12;}
              if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){contJogadas = 12;}
              if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){contJogadas = 12;}
        }while(contJogadas <= 9);
        tabuleiro(casas);
        if(contJogadas == 10){
            printf("\nJogo empatado\n");
        }if(contJogadas == 11){
            printf("\nJogador X e o vencedor\n");
        }if(contJogadas == 12){
            printf("\nJogador O e o vendedor\n");
        }
        printf("Deseja jogar novamente?[S-N]\n");
        scanf("%s", &res);
    }while(res == 's' || res == 'S');
}
