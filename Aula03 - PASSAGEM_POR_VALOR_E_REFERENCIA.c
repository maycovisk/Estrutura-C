//PASSAGEM POR VALOR E PASSAGEM POR REFERENCIA
#include<stdio.h>
#include<stdlib.h>

void VerificaParImpar(int numero1){
    if(numero1 % 2 == 0)
        printf("E par\n");
    else
        printf("E impar\n");
}

void trocaPorValor(int k, int l){           //PASSAGEM POR VALOR
    int aux;
    aux = k;
    k = l;
    l = aux;
}

void trocaPorReferencia(int *k, int *l){    //PASSAGEM POR REFERENCIA
    int aux;
    aux = *k;
    *k = *l;
    *l = aux;
}

int opcaomenu(){
    int opcao;
    printf("========= MENU =========\n");
    printf("|Entre com 0 para sair |\n");
    printf("|Entre com 1 para ex1. |\n");
    printf("|Entre com 2 para ex2. |\n");
    printf("|Entre com 3 para ex3. |\n");
    printf("========================\n");
    scanf("%d", &opcao);
    return opcao;
}

void limpa(){
    while(getchar() != '\n');
    printf("Digite algo para continuar...\n");
    getchar();
    system("cls");

}

void menu(){
    int opcao;
    int numero1, numero2;
    do{
        opcao = opcaomenu();
        switch(opcao)
        {
            case 0:
                printf("Obrigado por utilizar o SisteMarques.\n");
                break;
            case 1:
                printf("Entre com um numero a ser testado: ");
                scanf("%d", &numero1);
                VerificaParImpar(numero1);
                break;
            case 2:
                printf("Entre com os dois numeros: ");
                scanf("%d%d", &numero1, &numero2);
                printf("numero1: %d \tnumero2: %d\n", numero1, numero2);
                trocaPorValor(numero1,numero2);
                printf("numero1: %d \tnumero2: %d\n", numero1, numero2);
                break;
            case 3:
                printf("Entre com os dois numeros: ");
                scanf("%d%d", &numero1, &numero2);
                printf("numero1: %d \tnumero2: %d\n", numero1, numero2);
                trocaPorReferencia(&numero1, &numero2);
                printf("numero1: %d \tnumero2: %d\n", numero1, numero2);
                break;
            default: printf("Opcao invalida..."); break;
        }
        limpa();
    }while(opcao != 0);
}

int main(){
    menu();


    return 0;
}


//INT MAIN() NO INICIO
/*
#include<stdio.h>
#include<stdlib.h>
void VerificaParImpar();
int opcaomenu();
void limpa();
void menu();

int main(){
    menu();


    return 0;
}

void troca(int *k, int *l){

}

void VerificaParImpar(){
    int numero;

    printf("Entre com um numero a ser testado: ");
    scanf("%d", &numero);

    if(numero % 2 == 0)
        printf("E par\n");
    else
        printf("E impar\n");


}

int opcaomenu(){
    int opcao;
    printf("========= MENU =========\n");
    printf("|Entre com 0 para sair |\n");
    printf("|Entre com 1 para ex1. |\n");
    printf("========================\n");
    scanf("%d", &opcao);
    return opcao;
}

void limpa(){
    while(getchar() != '\n');
    printf("Digite algo para continuar...\n");
    getchar();
    system("cls");

}

void menu(){
    int opcao;
    do{
        opcao = opcaomenu();
        switch(opcao)
        {
            case 0: printf("Obrigado por utilizar o SisteMarques.\n"); break;
            case 1: VerificaParImpar(); break;
            default: printf("Opcao invalida..."); break;
        }
        limpa();
    }while(opcao != 0);
}

*/
