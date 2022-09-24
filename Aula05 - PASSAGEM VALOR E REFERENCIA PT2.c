//PASSAGEM DE PARAMETRO VALOR E REFERENCIA
#include<stdio.h>
#include<stdlib.h>

void altera(int *px, int *py){
    *px = 37;       //ALTERA O VALOR DA VARIAVEL ORIGINAL
    *py = 79;       //ALTERA O VALOR DA VARIAVEL ORIGINAL
}

int main(){
    int x = 3, y = 7;
    altera(&x, &y);
    printf("Valor de x: %d \nValor de y: %d", x, y);
    return 0;
}
