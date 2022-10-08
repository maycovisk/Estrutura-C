#include<stdio.h>
#include<stdlib.h>
#define MAX_TAM 10

typedef struct sLista{
    char elem[MAX_TAM];
    int ultimo;
}LISTA;

void inicializaLista(LISTA *lista){
    lista->ultimo = -1;
}

LISTA *lista = (LISTA *) malloc (sizeof(LISTA));
inicializaLista(lista);

int listaCheia(LISTA *lista){
    if(lista->ultimo == (MAX_TAM -1)){
        return 1;
    }
    return 0;
}

int listaVazia(LISTA *lista){
   if(lista->ultimo == -1){
    return 1;
   } 
   return 0;
}

//Inserir elemento no fim da lista
int insetirFim(LISTA *lista, char elemento){
    //Verifica se a lista esta cheia
    if(listaCheia(lista)){
        printf("ERRO: Lista cheia!\n");
        return 0;
    }
    lista->elem[lista->ultimo + 1] = elemento;
    lista->ultimo++;
    return 1;
}

int modificarElemento(LISTA *lista, int posicao, char elem){
    if(!listaVazia(lista)){
        //Verificar se  posicao e valida
        if(posicao >= 0 && posicao < lista->ultimo + 1){
            //Substitui o elemento
            lista->elem[posicao] = elem;
            //Significa que o elemento foi inserido com sucesso
            return 1;
        }
    }
    return 0;
}

int removerElemento(LISTA *lista, int posicao){
    int i;
    //Verifica se a lista esta vazia
    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia!");
        return 0;
    }
    //Testa se a posicao e invalida
    if(posicao < 0 || posicao > lista->ultimo){
        printf("\nERRO: Posicao Invalida!");
        return 0;
    }
    //Move os elementos posteriores ao removido
    for(i = posicao; i < lista->ultimo; i++){
        lista->elem[i] = lista->elem[i+1];
    }
    //Atualiza o indicador de ultimo elemento
    lista->ultimo--;
    retun 1;
}

char acessarElemento(LISTA *lista, int posicao){
    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia!");
        return ' ';
    }
    if(posicao < 0 || posicao > lista->ultimo){
        printf("\nERRO: Posicao Invaida!");
        return ' ';
    }
    return lista->elem[posicao];
}

int pesquisaElemento(LISTA *lista, char elem){
    int i;
    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia!");
        return -1;
    }
    //Percorre todos os elementos da Lista
    for(i = 0; i <= listta->ultimo; i++){
        if(lista->elem[i] == elem){
            return i; //Retorna posicao do elemento
        }
    }
    //Se percorreu a lista e nao encontrou o elemento
    return -1;
}

int tamanhoLista(LISTA *lista){
    return lista->ultimo+1;
}