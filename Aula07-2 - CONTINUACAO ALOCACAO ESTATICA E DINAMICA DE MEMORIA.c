//EXEMPLO3
#include<stdio.h>
#include<stdlib.h>
/*
int main(){
    int *p, *q;
    p = (int *) malloc(sizeof(int));
    q = p;
    *p = 10;
    *q = 20;
    free(p);
    q = NULL;
    return 0;
}



//EXEMPLO4
int main(){
    int *p, *q;
    p = (int *) malloc(sizeof(int));
    q = (int *) malloc(sizeof(int));
    *p = 10;
    *q = 20;
    *p = 10;
    *p = *q;
    free(p);
    free(q);
    return 0;
}

//EXEMPLO5
int main(){
    int *array1;
    array1 = malloc(100 * sizeof(int));
    if(array1 == NULL){
        printf("Nao foi possivel alocar memoria. \n");
        exit(0);
    }
    array1[99] = 301;
    printf("%d\n", array1[99]);
    free(array1);
    return 0;
}
*/

//EXEMPLO6
typedef struct cli{
    char nome[20];
    int idade;
}CLIENTE;

int main(){
        CLIENTE *pc;
        pc = (CLIENTE *) malloc(50 * sizeof(CLIENTE));
        gets(pc[0].nome);
        scanf("%d", &pc[0].idade);

        printf("%s\n", pc[0].nome);
        printf("%d", pc[0].idade);
        free(pc);
        return 0;
}
