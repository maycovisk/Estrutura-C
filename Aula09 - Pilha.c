#include<stdio.h>
#define TAM 5

typedef struct stack{
    int elem[TAM];
    int topo;
}PILHA;

void inicializar(PILHA *pilha){
    pilha->topo = -1;
}

int pilhaVazia(PILHA *pilha){
    if(pilha->topo == -1)
        return 1;
    return 0;
}

int pilhaCheia(PILHA *pilha){
    if(pilha->topo == (TAM-1))
        return 1;
    return 0;
}

int push(PILHA *pilha, int *elemento){
    if(pilhaCheia(pilha)){
        printf("\nERRO: Pilha Cheia.\n");
        return 0;
    }

    pilha->elem[pilha->topo+1] = elemento;
    pilha->topo++;
    return 1;
}

int pop(PILHA *pilha){
    int removido = -1;
    if(pilhaVazia(pilha)){
        printf("Nao ha elemento para remover.\n");
        return removido;
    }

    removido = pilha->elem[pilha->topo];
    pilha->topo--;
    return removido;
}

int topoEl(PILHA *pilha){
    int topo = -1;
    if(pilhaVazia(pilha)){
        printf("Nao ha nada na pilha.\n\n");
        return 0;
    }

    topo = pilha->elem[pilha->topo];
    printf("O elemento no topo da pilha e: %d.\n\n", pilha->elem[pilha->topo]);
    return topo;
}

void imprimirEEsvaziarPilha(PILHA *pilha){
    printf("Pilha: \" ");
    int i, removido = -1;
    if(pilhaVazia(pilha)){
        printf("Nao ha elemento para remover.\n");
        return removido;
    }
    for (i=pilha->topo;i>=0;i--) {
        printf("%i ", pilha->elem[i]);
    }
    printf("\"\n");

    for (i=pilha->topo;i>=0;i--) {
        removido = pilha->elem[pilha->topo];
        pilha->topo--;
    }

    printf("Pilha apagada.\n\n");
}

int menu(){
    int escolha;
    printf("================================== MENU =================================\n");
    printf("| 0 .............................................................. SAIR |\n");
    printf("| 1 ........................................ Acessar o topo sem remover |\n");
    printf("| 2 ............................................................ Push() |\n");
    printf("| 3 ............................................................. Pop() |\n");
    printf("| 4 ....................................... Imprimir e esvaziar a pilha |\n");
    printf("=========================================================================\n");
    printf("Opcao: ");
    scanf("%d", &escolha);
    system("cls");
    return escolha;
}

int main(){
    int escolha, tempElem;
    PILHA *pilha, *tempPilha;
    inicializar(&pilha);

    do{
        escolha = menu();
        switch (escolha)
        {
        case 0: printf("Obrigado por utilizar o Sistema!\n\n");
            break;
        case 1:
            topoEl(&pilha);
            break;
        case 2:
            printf("Digite o numero que deseja adicionar a pilha: ");
            scanf("%d", &tempElem);
            printf("\n\n");
            push(&pilha, tempElem);
            break;
        case 3:
            tempPilha = pop(&pilha);
            printf("O %d foi desempilhado.\n\n", tempPilha->elem);
            break;
        case 4:
            imprimirEEsvaziarPilha(&pilha);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }

    }while(escolha != 0);

    return 0;

}
