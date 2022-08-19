//Lista1Ex2
#include <stdio.h>

int main () {

    float n1,n2,n3,n4,n5,p1,p2,p3,p4,p5, mp; //n1,n2,n3,n4,n5 = numero1, numero2,..., p1,p2,p3,p4,p5 = peso1, peso2,..., mp = media ponderada

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

    mp = (n1 * p1) + (n2 * p2) + (n3 * p3) + (n4 * p4) + (n5 * p5) / (p1 + p2 + p3 + p4 + p5);

    printf("A media ponderada e %f", mp);

    return 0;
}
