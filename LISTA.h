#ifndef _LISTA_H
#define _LISTA_H
#define MAX_TAM 10
typedef struct sLista{
    char elem[MAX_TAM];
    int ultimo;
}LISTA;

void inicializaLista(LISTA *lista);
int listaCheia(LISTA *lista);
int listaVazia(LISTA *lista);
int insetirFim(LISTA *lista, char elemento[]);
int modificarElemento(LISTA *lista, int posicao, char elem);
int removerElemento(LISTA *lista, int posicao);
char acessarElemento(LISTA *lista, int posicao);
int pesquisaElemento(LISTA *lista, char elem);
int tamanhoLista(LISTA *lista);
#endif // _LISTA_H
