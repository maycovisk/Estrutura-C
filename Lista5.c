//Lista 5
//José Vinícius
//CJ3014657
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TAM 10
#include "LISTA.h"



void inicializaLista(LISTA *lista){

    lista->ultimo = -1;
}

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

int inserirFim(LISTA *lista, char elemento[]){
    if(listaCheia(lista)){
        printf("ERRO: Lista cheia!\n");
        return 0;
    }

    strncpy(lista->elem, elemento, MAX_TAM);
    return 1;
}

int modificarElemento(LISTA *lista, int posicao, char elem){
            lista->elem[posicao] = elem;
            return 1;
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
    return 1;
}

char acessarElemento(LISTA *lista, int posicao){
    printf("Elemento: %c na posicao: %d\n", lista->elem[posicao], posicao);
    return lista->elem[posicao];
}

int pesquisaElemento(LISTA *lista, char elem){
    int i;
    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia!\n");
        return -1;
    }
    //Percorre todos os elementos da Lista
    for(i = 0; i <= lista->ultimo; i++){
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

int imprimirLista(LISTA *lista){
    printf("String de elementos: %s\n", lista->elem);
}
int inserirEmPosicao(LISTA *lista, char elemento[], int posicao){
    if(listaCheia(lista)){
        printf("ERRO: Lista cheia!\n");
        return 0;
    }

    for(int i = posicao; i < lista->ultimo; i++) //adicionado o for para alterar as posicoes de todos
        lista->elem[i] = lista->elem[i+1];
    lista->elem[posicao] = *elemento;

    lista->ultimo++;
    return 1;
}

void inverterLista(LISTA *lista){
    int ultimaPosicao = MAX_TAM-1;
    int primeiraPosicao = 0;

    printf("Lista com o elemento: %s\n", lista->elem);
    LISTA *listaRef = (LISTA *) malloc (MAX_TAM * sizeof(LISTA));
    inicializaLista(listaRef);

    strncpy(listaRef->elem, lista->elem, MAX_TAM);

    for(int i=0; i<MAX_TAM; i++){
        strcpy(&listaRef->elem[primeiraPosicao], &lista->elem[ultimaPosicao]);
        primeiraPosicao++;
        ultimaPosicao--;
    }

    for(int i=0; i<MAX_TAM; i++) {
        printf("Lista com o elemento n%d: %c\n", i+1, listaRef->elem[i]);
    }
}

int menu(){
    int escolha;
    printf("======================== MENU ========================\n");
    printf("| 0 ........................................... SAIR |\n");
    printf("| 1 ............................... Inserir Elemento |\n");
    printf("| 2 ............................. Modificar Elemento |\n");
    printf("| 3 ............................... Remover Elemento |\n");
    printf("| 4 ............................... Acessar Elemento |\n");
    printf("| 5 ............................. Pesquisar Elemento |\n");
    printf("| 6 ....................... Imprimir Todos Elementos |\n");
    printf("| 7 .................. Inserir Elemento na posicao K |\n");
    printf("| 8 ............................... Inverter a Lista |\n");
    printf("| 9 ................................ Ordenar a Lista |\n");
    printf("======================================================\n");
    scanf("%d", &escolha);
    system("cls");
    return escolha;
}

int main(){
    char elem[MAX_TAM];
    char encontrarElemento;
    int ultimo, i, escolha;

    char tempString[MAX_TAM];
    char temp;

    int posEx2 = 0;
    LISTA *lista = (LISTA *) malloc (MAX_TAM * sizeof(LISTA));
    inicializaLista(lista);
    lista->ultimo = -1;

    do{
        escolha = menu();
        switch (escolha)
        {
        case 0:

            break;
        case 1:
            printf("Insira um novo elemento: ");
            scanf("%s", elem);
            inserirFim(lista, elem);
            break;
        case 2:
            printf("Digite o elemento a ser modificado: ");
            scanf("%s", elem);
            for(int i = 0; i < MAX_TAM; i++){
                printf("O elemento para modificar e: %c\n", lista->elem[i]);
                if(strcmp(&lista->elem[i], elem) == 0){//(strcmp(lista->elem[i], elem) == 0){   //COM ERRO AQUI
                    printf("Digite o novo elemento: ");
                    scanf(" %c", elem);
                    modificarElemento(lista, i, *elem);
                }
            }
            break;
        case 3:
            printf("Digite o elemento a ser removido: ");
            scanf("%s", elem);
            for(int i = 0; i < lista->ultimo; i++){
                printf("O elemento para remover e: %s\n", lista->elem[i]);
                if(strcmp(&lista->elem[i], elem) == 0){   //COM ERRO AQUI
                    printf("Digite o novo elemento: ");
                    scanf(" %s", &elem);
                    removerElemento(lista, i);
                }
            }
            break;
        case 4:
            printf("Digite o elemento a ser acessado: ");
            scanf(" %c", &encontrarElemento);
            for(int i = 0; i < MAX_TAM; i++){
                if(strcmp(&lista->elem[i], &encontrarElemento) == 0){//(strcmp(lista->elem[i], elem) == 0){   //COM ERRO AQUI
                    acessarElemento(lista, i);
                }
            }
            break;
        case 5:
            printf("Digite o elemento para a pesquisa: ");
            scanf("%s", elem);
            pesquisaElemento(lista, elem);
            printf("\nO elemento pesquisa e %s na posicao %d\n", &lista->elem[i], i);  //i RETORNA DA FUNCAO
            break;
        case 6:
            imprimirLista(lista);
            break;
        case 7:
            printf("Digite a posicao que queira adicionar: ");
            scanf(" %d", &posEx2);
            printf("Digite a posicao que queira adicionar: ");
            scanf("%s", elem);
            if(posEx2 < MAX_TAM && posEx2 > 0) {
                inserirEmPosicao(lista, elem, posEx2);
                printf("Lista com o elemento: %s na posicao %d\n", &lista->elem[posEx2], posEx2);
            } else printf("Posicao Invalida!");
            break;
        case 8:
            printf("Insira os elementos: ");
                for (int i = 0; i<MAX_TAM; i++) {
                    scanf("%s", &lista->elem[i]);
                }
                inverterLista(lista);
            break;
        case 9:
            printf("Insira os elementos: ");
                for (int i = 0; i<MAX_TAM; i++) {
                    scanf("%s", &lista->elem[i]);
                }
                strncpy(tempString, lista->elem, MAX_TAM);
            printf("String antes de ordenar - %s \n", tempString);

                for (int i = 0; i < strlen(tempString)-1; i++) {
                    for (int j = i+1; j < strlen(tempString); j++) {
                        if (tempString[i] > tempString[j]) {
                            temp = tempString[i];
                            tempString[i] = tempString[j];
                            tempString[j] = temp;
                        }
                    }
                }

                printf("String depois de ordenar  - %s \n", tempString);
                return 0;
                break;
        default:
            printf("Opcao invalida!\n");
            break;
        }

    }while(escolha != 0);

    return 0;
}
