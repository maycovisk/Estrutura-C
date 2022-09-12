#include<stdio.h>
#include<stdlib.h>

void ex2(){
    int a, b, x;
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    x = a;
    a = b;
    b = x;

    printf("O valor de a e %d e o valor de b e %d\n\n", a,b);
}

void ex3(){
    int a, b;
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);


    printf("O valor de a e %d e o valor de b e %d\n\n", b, a);
}

void ex4(){
    float valor, gorjeta, resultado;
    int pessoas;
    printf("Digite o valor da conta: ");
    scanf("%f", &valor);
    printf("Digite o valor da gorjeta em percentual %%: ");
    scanf("%f", &gorjeta);
    printf("Digite o numero de pessoas: ");
    scanf("%d", &pessoas);

    resultado = (valor + (valor * gorjeta / 100)) / pessoas;


    printf("O valor da conta e de %.2f reais para cada\n\n", resultado);
}

void ex5(){
    float valorDia = 45, desconto = 8, valorDesconto, valorBruto, valorLiquido;
    int dia;
    printf("Digite quantidade de dias trabalhado: ");
    scanf("%d", &dia);

    valorBruto = valorDia * dia;
    valorDesconto = valorBruto * desconto / 100;
    valorLiquido = valorBruto - valorDesconto;


    printf("O quantia a ser paga ao encanador e de %.2f\n\n", valorLiquido);
}

void ex6(){
    float valorDollar = 5.30, valorReal, resultado;
    printf("Digite o valor em reais: ");
    scanf("%f", &valorReal);

    resultado = valorReal * valorDollar;


    printf("O valor de %.2f reais em dolares e %.2f dolares\n\n", valorReal, resultado);
}

void ex7(){
    int segundos, h, m, s, resto;
    printf("Digite o valor em segundos: ");
    scanf("%d", &segundos);

    h = segundos / 3600;
    resto = segundos % 3600;
    m = resto / 60;
    s = resto % 60;

    printf("A conversao dos segundos em horas, minutos e segundos e: %d:%d:%d\n\n", h, m, s);
}

int opcaomenu(){
    int opcao;
    printf("========= MENU =========\n");
    printf("|Entre com 0 para sair |\n");
    printf("|Entre com 2 para ex2. |\n");
    printf("|Entre com 3 para ex3. |\n");
    printf("|Entre com 4 para ex4. |\n");
    printf("|Entre com 5 para ex5. |\n");
    printf("|Entre com 6 para ex6. |\n");
    printf("|Entre com 7 para ex7. |\n");
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
            case 0: printf("Saindo.\n"); break;
            case 2: ex2(); break;
            case 3: ex3(); break;
            case 4: ex4(); break;
            case 5: ex5(); break;
            case 6: ex6(); break;
            case 7: ex7(); break;
            default: printf("Opcao invalida..."); break;
        }
        limpa();
    }while(opcao != 0);
}

int main(){
    menu();


    return 0;
}
