//PONTEIRO
#include <stdio.h>
#include <stdlib.h>

/*EXEMPLOS:
int * ponteiro1;
float * ponteiro2;
char * ponteiro3;
struct MinhaEStrutura * ponteiro4;

int *variavel = NULL

ERRADO:
int a = 5;
int * p = NULL;
*p = a;     //*p espera endereço

int a = 5;
int * p = NULL
*p = &a;    //&a indica conteudo

CERTO:
int a = 5;
int * p = NULL;
p = &a;

int * p;
p = (int*) malloc(sizeof(int)); //aloca dinamica de memoria
*p = 5;

*/
int main(void){
    int a = 5;
    int * p = malloc(sizeof(int));
    *p = 10;
    printf("Endereco de P: %p\n", &p);
    printf("%p\n", p);
    printf("%d\n", *p);
    return 0;
}
