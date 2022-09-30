//EXEMPLO1
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p;
    p = (int *)/*chamado de CAST*/ malloc(sizeof(int)); //CAST forca que o endereco seja compativel com o tipo
    if(p == NULL){
        printf("Nao foi possivel alocar memoria.\n");
        exit(0);
    }
    *p = 5;
    printf("%d\n", *p);
    free(p);    //libera memoria alocada
    return 0;
}


/*  *p  aponta o valor
     p  aponta o endereco onde esta o valor
    &p  aponta o endereco do ponteiro
*/

