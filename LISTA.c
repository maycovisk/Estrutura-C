#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define semana 4.5

void ex1(){
    float valorhora,percdesc,salarioliq,valordesc,salariobruto, hora;
    printf("\n\nEXERCICIO1\nAPRESENTAR SALARIO LIQUIDO DO PROGRAMADOR \nCONSIDERANDO QUE EM MEDIA TEM-SE 4,5 SEMANAS A CADA MES");

    printf("\n\nDigite o valor pago por hora: ");
    scanf("%f", &valorhora);

    printf("\nDigite o numero de horas por semana: ");
    scanf("%f", &hora);

    printf("\nDigite o percentual de desconto a ser retido para INSS: ");
    scanf("%f", &percdesc);

    salariobruto = (valorhora * (hora * semana));  //salarioliq = (valorhora * (hora * semana)) * (1-(percdesc/100));
    valordesc = (percdesc / 100) * salariobruto;
    salarioliq = salariobruto - valordesc;

    printf("\n\nO salario liquido mensal do programador e: %.2f", salarioliq);

    return enter();

}

void ex2(){
    float n1,n2,n3,n4,n5,p1,p2,p3,p4,p5, medponderada; //n1,n2,n3,n4,n5 = numero1, numero2,..., p1,p2,p3,p4,p5 = peso1, peso2,..., mp = media ponderada
    printf("\n\nEXERCICIO2\nENTRAR COM 5 NUMEROS E 5 PESOS \nE APRESENTAR A MEDIA PONDERADA");

    printf("\n\nEntre o numero 1: ");
    scanf("%f", &n1);
    printf("Entre com o peso associado ao numero 1: ");
    scanf("%f", &p1);
    printf("\nEntre o numero 2: ");
    scanf("%f", &n2);
    printf("Entre com o peso associado ao numero 2: ");
    scanf("%f", &p2);
    printf("\nEntre o numero 3: ");
    scanf("%f", &n3);
    printf("Entre com o peso associado ao numero 3: ");
    scanf("%f", &p3);
    printf("\nEntre o numero 4: ");
    scanf("%f", &n4);
    printf("Entre com o peso associado ao numero 4: ");
    scanf("%f", &p4);
    printf("\nEntre o numero 5: ");
    scanf("%f", &n5);
    printf("Entre com o peso associado ao numero 5: ");
    scanf("%f", &p5);

    medponderada = (n1 * p1 + n2 * p2 + n3 * p3 + n4 * p4 + n5 * p5) / (p1 + p2 + p3 + p4 + p5);

    printf("A media ponderada e %.2f", medponderada);

    return enter();

}

void ex3(){
    int numero;
    printf("\n\nEXERCICIO3\nENTRAR COM UM VALOR E VERIFICAR SE E NEGATIVO, \nZERO OU POSITIVO, SE NEGATIVO, APRESENTE");
    printf("\nO NUMERO AO QUADRADO, SE POSITIVO APRESENTE \nA RAIZ QUADRADA DELE E SE CASO SEJA ZERO, APRESENTE \nA MENSAGEM AO USUARIO QUE O NUMERO E ZERO");

    printf("\n\nDigite um numero qualquer: ");
    scanf("%d", &numero);

    if(numero < 0)
        printf("\nO numero %d elevado ao quadro e %d", numero, numero * numero);
    else if(numero > 0)
        printf("\nA raiz quadrada do numero %d e %.2f", numero, sqrt(numero));
    else
        printf("\nO numero digitado e ZERO");

    return enter();

}

void ex4(){
    int minuto, velocidade;
    float distancia;
    printf("\n\nEXERCICIO4\nCALCULAR A DISTANCIA TOTAL PERCORRIDA POR UM VEICULO");

    printf("\n\nDigite o tempo percorrido em minuto: ");
    scanf("%d", &minuto);

    printf("\nDigite a velocidade km/h: ");
    scanf("%d", &velocidade);

    distancia = velocidade * (minuto / 60.0);

    printf("\nA distancia percorrida e %.2f km/h", distancia);

    return enter();

}

void ex5(){
    int numero;
    printf("\n\nEXERCICIO5\nVERIFICAR SE O NUMERO E DIVISIVEL POR 4, POR 5 OU POR AMBOS");

    printf("\n\nDigite um numero qualquer: ");
    scanf("%d", &numero);

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

    return enter();

}

void ex6(){
    float a, b, c, delta, x1, x2;
    printf("\n\nEXERCICIO6\nDETERMINAR AS RAIZES DE UMA EQUACAO DE 2 GRAU");

    printf("\n\nDigite o valor de A: ");
    scanf("%f", &a);
    printf("\nDigite o valor de B: ");
    scanf("%f", &b);
    printf("\nDigite o valor de C: ");
    scanf("%f", &c);

    if(a == 0){
        printf("Nao e uma equacao de segundo grau");
        return 0;
    }

    delta = pow(b, 2) - 4 * a * c;
    if(delta <  0){
        printf("\nNao existem raizes reais");
        return 0;
    }

    if(delta == 0){
        x1 = ((b + sqrt(delta)) / 2 * a);
        printf("A unica raiz e %.2f", x1);
    }
    else{
        x1 = ((-b + sqrt(delta)) / 2 * a);
        x2 = ((-b - sqrt(delta)) / 2 * a);
        printf("As raizes sao %.2f e %.2f", x1, x2);
    }

    return enter();

}

void ex7(){
    char caract;
    printf("\n\nEXERCICIO7(DESAFIO)\nINFORMAR O QUAL O CODIGO DECIMAL E HEXADECIMAL DO CARACTERE DIGITADO");

    printf("\n\nDigite um caractere do teclado: ");
    caract = getchar();
    printf("\nO caractere %c tem o valor decimal %i e o valor hexadecimal e %x", caract, caract, caract);

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
            case 3 : ex3(); break;
            case 4 : ex4(); break;
            case 5 : ex5(); break;
            case 6 : ex6(); break;
            case 7 : ex7(); break;
            case 0 : exit(0);
            default : printf("Opcao invalida!");
        }
    }while(opcao != 0);

    return 0;
}
