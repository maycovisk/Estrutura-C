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
printf("\nEXERCICIO 2 \nProgama que calcule e escreva \na soma: 1/1 + 3/2 + 5/3 + 7/4...+ 99/50.\n\n");
float div, divid, soma;


for(div = 1, divid = 1; divid <= 50; div = div +2, divid = divid+1){

    soma = (div / divid) + soma;
    }
printf("Soma total e %.2f", soma);

return enter();
}

void ex3(){
printf("\nEXERCICIO 3 \nProgama que calcule a soma dos \nnumeros digitados pelo usuario.\n\n");
int numero, soma = 0;

do{
    soma == 0;
    printf("Resultado total: %d\n", soma);
    printf("Digite um numero para somar ao resultado total: ");
    scanf("%d", &numero);

    soma = numero + soma;

    printf("\nPara encerrar a soma digite 0 (ZERO)...\n\n");
}while(numero != 0);

return enter();
}

void ex4(){
printf("\nEXERCICIO 4 \nProgama que mostre os numeros com \nresto igual a 5 quando dividido por 13, entre 1000 a 1999.\n\n");
int numero, div = 13;
for(numero = 1000; numero <= 1999; numero++){
    if(numero % div == 5)
        printf("%d dividido por 13 possue resto igual a 5\n", numero);
}

return enter();
}

void ex5(){
printf("\nEXERCICIO 5 \nPrograma para gerar N primeiros \ntermos da sequencia.\n\n");
int n1 = 1, n2 = 1, sequencia = 0, contagem = 2, valorN;
printf("Digite valor de N para apresentar esse valor de sequencia: ");
scanf("%d", &valorN);
printf("%d - %d ", n1, n2);

do{

    sequencia = n1 + n2;
    printf("- %d ", sequencia);
    n1 = n2;
    n2 = sequencia;

    contagem++;
}while(contagem < valorN);

return enter();

}

void ex6(){
printf("\nEXERCICIO 6 \nPrograma para ler 12 numeros inteiros POSITIVOS, \nexibir o resultado das soma dos numeros impares e pares.\n\n");
int numero = 0, impar = 0, par = 0, i;

for(i = 1; i <= 12; i++){
    printf("Digite o %do valor: ", i);
    scanf("%d", &numero);
        if(numero >= 0){

            if(numero % 2 == 0){
                par = numero + par;
            }
            else if(numero % 2 != 0){
                impar = numero + impar;
            }
        } else {
            printf("Valor invalido, execucao cancelada...");
            return enter();
        }

}


printf("A soma dos numeros impares: %d\nA soma dos numeros pares: %d", impar, par);
return enter();
}

void ex7(){
printf("\nEXERCICIO 7 \nPrograma de LPF para lancamento \nde 5 notas para calcular a media final.\n\n");
float nota = 0, media, soma;
int i;

for(i = 1; i <= 5; i++){
    printf("Digite a %da nota: ", i);
    scanf("%f", &nota);

    soma = nota + soma;
}

media = soma / 5;
printf("\nA media final do aluno e: %.2f",media);

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
        printf("\n\n1...............................Exercicio01");
        printf("\n2...............................Exercicio02");
        printf("\n3...............................Exercicio03");
        printf("\n4...............................Exercicio04");
        printf("\n5...............................Exercicio05");
        printf("\n6...............................Exercicio06");
        printf("\n7...............................Exercicio07");
        printf("\n8...............................Exercicio08");
        printf("\n9...............................Exercicio09");
        printf("\n10..............................Exercicio10");
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
            case 3 : ex3(); break;
            case 4 : ex4(); break;
            case 5 : ex5(); break;
            case 6 : ex6(); break;
            case 7 : ex7(); break;
            //case 8 : ex8(); break;
            //case 9 : ex9(); break;
            //case 10 : ex10(); break;
            case 0 : exit(0);
            default : printf("Opcao invalida!");
        }
    }while(opcao != 0);

    return 0;
}
