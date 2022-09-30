//EXEMPLO1
#include<stdio.h>
#include<stdlib.h>

struct sEndereco{
    char rua[10];
    int numero[10];
};

int main(){
        struct sEndereco *pEnd;
        pEnd = (struct sEndereco *) malloc(sizeof(struct sEndereco));
        if(pEnd == NULL){
            printf("Nao foi possivel alocar memoria. \n");
            exit;
        }
        return 0;
}
