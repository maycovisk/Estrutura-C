//LISTA1-ex1
#include <stdio.h>

int main () {
    float vh,perd,sll,vd,slb, hs;  //vh = valor hora , perd = percentual de desconto , sll = salario liquido, vd = valor desconto, slb = salario bruto, hs = horas por semana
    float semana = 4.5;

    printf("Digite o valor pago por hora: ");
    scanf("%f", &vh);

    printf("\nDigite o numero de horas por semana: ");
    scanf("%f", &hs);

    printf("\nDigite o percentual de desconto a ser retido para INSS: ");
    scanf("%f", &perd);

    slb = (vh * (hs * semana));
    vd = (perd / 100) * slb;
    sll = slb - vd;

    printf("\n\nO salario liquido mensal do programador e: %.2f", sll);

    return 0;
}
