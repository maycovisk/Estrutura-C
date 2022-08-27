#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void ex1(){
float numero, menor, maior;
int cont = 1;

printf("\nEXERCICIO 1 \nEscreva um programa que leia 12 valores reais, \nencontra o maior e o menor deles e mostra o resultado.\n\n");

while(cont <= 12){
    printf("Digite %do numero real: ",cont);
    scanf("%f", &numero);
    if(cont == 1){
        maior = numero;
        menor = numero;
    }
    else if(numero > maior){
        maior = numero;
    }
    else if(numero < menor){
        menor = numero;
    }
    cont++;
}
printf("O menor numero e %.2f e o maior e %.2f", menor, maior);

return enter();

}

void ex2(){
float div, divid, soma, resultado;
    for(div = 1, divid = 1; div <= 90, divid <= 50; div+2, divid++){
        if (div == 1){
            soma = 0;
        }
        else{
            resultado = (div / divid) + soma;
        }
    }
    printf("Soma total e %.2f", soma);

return enter();
}



void enter(){

    while((getchar()) != '\n');
    printf("\n\nPressione ENTER para voltar ao MENU INICIAL...\n\n");
    getchar();
    system("cls");  //usado para WINDOWS
    //system("clear"); //usado para LINUX
    return main();
}


int  menu(){
    int opcao;

    do{
        printf("LISTA 1");
        printf("\n\n1...............................Exercicio1");
        printf("\n2...............................Exercicio2");
        printf("\n3...............................Exercicio3");
        printf("\n4...............................Exercicio4");
        printf("\n5...............................Exercicio5");
        printf("\n6...............................Exercicio6");
        printf("\n7...............................Exercicio7");
        printf("\n0.....................................Sair");
        printf("\n\nDigite o numero da opcao desejada: ");
        scanf("%d", &opcao);
    }while(opcao < 0 || 7 < opcao);

}

int main(){
    int opcao = menu();

    do{
        while((getchar()) != '\n');
        switch(opcao){
            case 1 : ex1(); break;
            case 2 : ex2(); break;
            //case 3 : ex3(); break;
            //case 4 : ex4(); break;
            //case 5 : ex5(); break;
            //case 6 : ex6(); break;
            //case 7 : ex7(); break;
            case 0 : exit(0);
            default : printf("Opcao invalida!");
        }
    }while(opcao != 0);

    return 0;
}
