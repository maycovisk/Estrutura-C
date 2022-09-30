//EXEMPLO1
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p;
    p = (int *)/*CAST*/ malloc(sizeof(int));
    if(p == NULL){
        printf("Nao foi possivel alocar memoria.\n");
        exit(0);
    }
    *p = 5;
    printf("%d\n", *p);
    free(p);
    return 0;
}
