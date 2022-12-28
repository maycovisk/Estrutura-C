#include<stdio.h>

typedef struct sPessoa{
    char nome[50];
    int matricula;
}PESSOA;

typedef struct sCell{
    PESSOA info;
    struct sCell *next;
}CELULA;

CELULA* criarCelula(){
    CELULA *nova = (CELULA *) malloc(sizeof(CELULA));
    return nova;
}

void inicializaLista(CELULA **lista){
    (*lista) = NULL;
}

int listaVazia(CELULA **lista){
    if((*lista) == NULL)
        return 1;
    return 0;
}

int inserirInicio(CELULA **lista, PESSOA *elemento){
    CELULA *novaCelula = criarCelula();
    if(novaCelula == NULL){
        printf("\nERRO: Memoria Cheia");
        return 0;
    }

    if(listaVazia(lista)){
        return inserirFim(lista, elemento);
    }

    novaCelula->info = *elemento;

    novaCelula->next = (*lista);
    (*lista) = novaCelula;
    return 1;
}

int inserirFim(CELULA **lista, PESSOA *elemento){
    CELULA *novaCelula;
    CELULA *auxiliar;

    novaCelula = criarCelula();
    if(novaCelula == NULL){
        printf("\nERRO: Memoria Cheia");
        return 0;
    }

    novaCelula->info = *elemento;
    novaCelula->next = NULL;

    if(listaVazia(lista)){
        (*lista) = novaCelula;
        return 1;
    }

    auxiliar = (*lista);

    while(auxiliar->next != NULL){
        auxiliar = auxiliar->next;
    }

    auxiliar->next = novaCelula;
    return 1;
}

void imprimirElemento(PESSOA elemento){
    printf("\nMatricula: %d \tNome: %s", elemento.matricula, elemento.nome);
}

void imprimirLista(CELULA **lista){
    CELULA *auxiliar = (*lista);
    if(listaVazia(lista)){
        printf("\nLista Vazia\n\n");
    }else{
        printf("\nLista: ");
        while(auxiliar != NULL){
            imprimirElemento(auxiliar->info);
            auxiliar = auxiliar->next;
        }
        printf("\n");
    }
}

void removerInicio(CELULA **lista){
    CELULA *removida;

    PESSOA removido;
    strcpy(removido.nome,"");
    removido.matricula = -1;

    if(listaVazia(lista)){
        printf("\nERRO: Lista vazia");
        return removido;
    }

    removida = (*lista);
    removido = removida->info;

    (*lista) = (*lista)->next;

    free(removida);
    return removido;
}

void removerFim(CELULA **lista){
    CELULA *removida;
    CELULA *anterior;

    PESSOA removido;
    strcpy(removido.nome,"");
    removido.matricula = -1;

    if(listaVazia(lista)){
        printf("\nERRO: Lista vazia");
        return removido;
    }

    if((*lista)->next == NULL)
        return removerInicio(lista);
    removida = (*lista);
    while(removida->next != NULL){
        anterior = removida;
        removida = removida->next;
    }

    removido = removida->info;
    anterior->next = NULL;
    free(removida);
    return removido;
}

void *pesquisarMatricula(CELULA **lista, int mat){
    CELULA *auxiliar;
    printf("A pesquisa e a matricula: %d\n\n", mat);

    if(listaVazia(lista)){
        printf("ERRO: Lista Vazia.\n");
        return NULL;;
    }

    auxiliar = (*lista);
    while(auxiliar != NULL){
        if(auxiliar->info.matricula == mat){
            return auxiliar;
        }
        auxiliar = auxiliar->next;
    }

    return NULL;
}

void removeMatr(CELULA **lista, int mat){
    CELULA *removida;
    CELULA *anterior;
    PESSOA pRemover;
    strcpy(pRemover.nome,"");
    pRemover.matricula = -1;

    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia");
        return pRemover;
    }

    removida = pesquisarMatricula(lista, mat);
    if(removida == NULL){
        printf("\nERRO: Matricula nao encontrada");
        return pRemover;
    }

    if(removida == (*lista)){
        return removerInicio(lista);
    }

    pRemover = removida->info;

    anterior = (*lista);

    while(anterior->next != removida){
        anterior = anterior->next;
    }

    anterior->next = removida->next;
    free(removida);

    return pRemover;
}

void retornarTamanhoDaLista(CELULA **lista) {
    CELULA *auxiliar;
    int counter = 0;
    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia");
        return 1;
    }

    auxiliar = (*lista);

    while(auxiliar->next != NULL){
        auxiliar = auxiliar->next;
        counter++;
    }

    printf("O tamanho da lista e: %d\n", counter+1);
}

int menu(){
    int escolha;
    printf("================================== MENU =================================\n");
    printf("| 0 .............................................................. SAIR |\n");
    printf("| 1 .................................................... Imprimir lista |\n");
    printf("| 2 ................................................. Inserir no inicio |\n");
    printf("| 3 .................................................... Inserir no fim |\n");
    printf("| 4 ................................................. Remover no inicio |\n");
    printf("| 5 .................................................... Remover no fim |\n");
    printf("| 6 ............................... Pesquisar endereco de uma matricula |\n");
    printf("| 7 ............................................. Remover por matricula |\n");
    printf("| 8 ......................................... Retornar tamanho da lista |\n");
    printf("=========================================================================\n");
    printf("Opcao: ");
    scanf("%d", &escolha);
    system("cls");
    return escolha;
}

int main(){
    int escolha;
    PESSOA temp;
    CELULA *ptrlista, *tempCel;
    criarCelula(&ptrlista);
    inicializaLista(&ptrlista);

    do{
        escolha = menu();
        switch (escolha)
        {
        case 0: printf("Obrigado por utilizar o Sistema!\n");
            break;
        case 1: imprimirLista(&ptrlista);
            break;
        case 2:
            printf("Digite o numero de matricula do aluno: ");
            scanf(" %d", &temp.matricula);
            printf("Digite o nome do aluno: ");
            scanf(" %s", &temp.nome);
            inserirInicio(&ptrlista, &temp);
            printf("Processo finalizado\n");
            break;
        case 3:
            printf("Digite o numero de matricula do aluno: ");
            scanf(" %d", &temp.matricula);
            printf("Digite o nome do aluno: ");
            scanf(" %s", &temp.nome);
            inserirFim(&ptrlista, &temp);
            printf("Processo finalizado\n");
            break;
        case 4:
            removerInicio(&ptrlista);
            printf("Processo finalizado\n");
            break;
        case 5:
            removerFim(&ptrlista);
            printf("Processo finalizado\n");
            break;
        case 6:
            printf("Digite o numero da matricula para pesquisa: ");
            scanf("%d", &temp.matricula);
            tempCel = pesquisarMatricula(&ptrlista, temp.matricula);
            printf("O endereco da matricula e: %d\n", tempCel);
            printf("Processo finalizado\n");
            break;
        case 7:
            printf("Digite o numero da matricula para excluir: ");
            scanf("%d", &temp.matricula);
            removeMatr(&ptrlista, temp.matricula);
            printf("Processo finalizado\n");
            break;
        case 8:
            retornarTamanhoDaLista(&ptrlista);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }

    }while(escolha != 0);

    return 0;

}
