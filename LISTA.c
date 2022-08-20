#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define semana = '4.5'

void ex1(){
    float valorhora,percdesc,salarioliq,valordesc,salariobruto, hora;

    printf("Digite o valor pago por hora: ");
    scanf("%f", &valorhora);

    printf("\nDigite o numero de horas por semana: ");
    scanf("%f", &hs);

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

    printf("Digite um numero qualquer: ")
    scanf("%d", &numero);

    if(numero < 0)
        printf("O numero %d elevado ao quadro e %d", numero, numero * numero);
    else if(numero > 0)
        printf("A raiz quadrada do numero %d e %d", numero, sqrt(numero));
    else
        printf("O numero digitado e ZERO");

}

void ex4(){
    int minuto, velocidade;
    float distancia;

    printf("Digite o tempo percorrido em minuto: ");
    scanf("%d", &minuto);

    printf("Digite a velocidade km/h: ");
    scanf("%d", &velocidade);

    distancia = velocidade * (minuto / 60.0);

    printf("A distancia percorrida e %f", distancia)

}

void ex5(){


}
