#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define semana 4.5

void ex1(){
    float valorhora,percdesc,salarioliq,valordesc,salariobruto, hora;

    printf("Digite o valor pago por hora: ");
    scanf("%f", &valorhora);

    printf("\nDigite o numero de horas por semana: ");
    scanf("%f", &hora);

    printf("\nDigite o percentual de desconto a ser retido para INSS: ");
    scanf("%f", &percdesc);

    salariobruto = (valorhora * (hora * semana));  //salarioliq = (valorhora * (hora * semana)) * (1-(percdesc/100));
    valordesc = (percdesc / 100) * salariobruto;
    salarioliq = salariobruto - valordesc;

    printf("\n\nO salario liquido mensal do programador e: %.2f", salarioliq);

}

void ex2(){
    float n1,n2,n3,n4,n5,p1,p2,p3,p4,p5, medponderada; //n1,n2,n3,n4,n5 = numero1, numero2,..., p1,p2,p3,p4,p5 = peso1, peso2,..., mp = media ponderada

    printf("Entre o numero 1: ");
    scanf("%f", &n1);
    printf("Entre com o peso associado ao numero 1: ");
    scanf("%f", &p1);
    printf("\n\nEntre o numero 2: ");
    scanf("%f", &n2);
    printf("Entre com o peso associado ao numero 2: ");
    scanf("%f", &p2);
    printf("\n\nEntre o numero 3: ");
    scanf("%f", &n3);
    printf("Entre com o peso associado ao numero 3: ");
    scanf("%f", &p3);
    printf("\n\nEntre o numero 4: ");
    scanf("%f", &n4);
    printf("Entre com o peso associado ao numero 4: ");
    scanf("%f", &p4);
    printf("\n\nEntre o numero 5: ");
    scanf("%f", &n5);
    printf("Entre com o peso associado ao numero 5: ");
    scanf("%f", &p5);

    medponderada = (n1 * p1 + n2 * p2 + n3 * p3 + n4 * p4 + n5 * p5) / (p1 + p2 + p3 + p4 + p5);

    printf("A media ponderada e %.2f", medponderada);

}

void ex3(){
    int numero;

    printf("Digite um numero qualquer: ");
    scanf("%d", &numero);

    if(numero < 0)
        printf("\nO numero %d elevado ao quadro e %d", numero, numero * numero);
    else if(numero > 0)
        printf("\nA raiz quadrada do numero %d e %d", numero, sqrt(numero));
    else
        printf("\nO numero digitado e ZERO");

}

void ex4(){
    int minuto, velocidade;
    float distancia;

    printf("Digite o tempo percorrido em minuto: ");
    scanf("%d", &minuto);

    printf("\nDigite a velocidade km/h: ");
    scanf("%d", &velocidade);

    distancia = velocidade * (minuto / 60.0);

    printf("\nA distancia percorrida e %f", distancia);

}

void ex5(){
    int numero;

    printf("Digite um numero qualquer: ");
    scanf("%d", numero);

    if(numero % 4 == 0 && numero % 5 == 0){
        printf("\nO numero %d e divisivel por 4 e por 5", numero);
    }
    else if(numero % 4 == 0){
        printf("\nO numero %d e divisivel por 4 mas nao por 5", numero);
    }
    else if(numero % 5 == 0){
        printf("\nO numero %d e divisivel por 5 mas nao por 4", numero);
    }
    else{
        printf("\nO numero %d nao e divisivel nem por 4 e nem por 5", numero);
    }

}

void menu(){
    int opcao;

    do{
        printf("LISTA 1");
        printf("\n\nExercicio1...............................1");
        printf("\n\nExercicio2...............................2");
        printf("\n\nExercicio3...............................3");
        printf("\n\nExercicio4...............................4");
        printf("\n\nExercicio5...............................5");
        printf("\n\nExercicio6...............................6");
        printf("\n\nExercicio7...............................7");
        printf("\n\nSair.....................................0");
        printf("\n\nDigite o numero da opcao desejada: ");
        scanf("%d", &opcao);
    }while(opcao < 0 || 5 < opcao);

}

int main(){
    int opcao;

    do{
        while(getchar() != "/n");
        opcao = menu();
        switch(opcao){
            case 1 : ex1(); break;
            case 2 : ex2(); break;
            case 3 : ex3(); break;
            case 4 : ex4(); break;
            case 5 : ex5(); break;
            //case 6 : ex6; break;
            //case 7 : ex7; break;
            default : printf("Opcao invalida!");
        }
    }while(opcao);

    getch();
    return 0;
}

