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
*p = a;     //*p espera endere�o

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
    int * p = malloc(sizeof(int));  //malloc(3 * sizeof(int)) >>> CRIA VETOR DE 3 ESPACOS
    p = &a;     //&a indica endereço
    *p = 10;    //*p indica conteudo
    printf("Endereco do ponteiro : %p\n", &p);
    printf("Endereco da variavel a : %p\n", p);
    printf("Conteudo de onde o ponteiro aponta : %d\n", *p);
    printf("Conteudo de a : %d\n", a);
    printf("Endereco da variavel a : %p\n", &a);
    return 0;
}
