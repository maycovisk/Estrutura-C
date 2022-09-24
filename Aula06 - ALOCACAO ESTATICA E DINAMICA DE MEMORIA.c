//ALOCACAO DINAMICA DE MEMORIA >> NECESSARIO BIBLIOTECA stdlib.h
#include<stdio.h>
#include<sdtlib.h>

/*
malloc() - A FUNCAO malloc() RETORNA O ENDERECO DE MEMORIA DO PRIMEIRO BYTE DE UMA REGIAO DE MEMORIA DO TAMANHO SIZE ALOCADA
QUANDO NAO HA MEMORIA DISPONIVEL, malloc RETORNA NULL


O cast DA FUNCAO malloc() - (float*) - GARANTE QUE O ENDERECO DE MEMORIA RETORNADO E PARA O TIPO ESPECIFICADO NA DECLARACAO DO APONTADOR
ALGUNS COMPILADORES REQUEREM OBRIGATORIAMENTE O cast


free() - LIMPA MEMORIA ALOCADA PELO malloc()
*/


int main(void){
    int a = 5;
    int b = 20;
    int * p;
    while(a < b){
        p = malloc(2000000 * sizeof(int));
        print("vai/n");
    }
    return 0;

}
