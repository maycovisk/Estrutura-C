//EXERCICIO - LISTA
#include<stdio.h>
#include<stdlib.h>


void ex1(){
    int *pN1, *pN2;
    pN1 = (int *) malloc(sizeof(int));
    pN2 = (int *) malloc(sizeof(int));
    printf("Digite dois numeros inteiros: ");
    scanf("%d%d", &pN1, &pN2);
    printf("%d e %d\n", pN1,pN2);
}

void ex2(){

}

short menu(){
    int opcao;

    do{
        printf("EXERCICIOS");
        printf("\n\n1...............................Exercicio1");
        printf("\n2...............................Exercicio2");
        printf("\n3...............................Exercicio3");
        printf("\n4...............................Exercicio4");
        printf("\n5...............................Exercicio5");
        printf("\nDigite a opcao desejada:");
        scanf("%d",&opcao);
    }while(opcao < 0 || opcao > 5);
}

int main(){
    int opcao = menu();

    do{
        while((getchar()) !='\n');
        switch(opcao){
        case 1: ex1(); break;
        case 2: ; break;
        case 3: ; break;
        case 4: ; break;
        case 5: ; break;
        case 0: exit(0); break;
        default: printf("opcao invalida...");
        }
    }while(opcao != 0);

    return 0;
}
