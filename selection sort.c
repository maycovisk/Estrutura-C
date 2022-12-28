#include <stdio.h>
#include <stdlib.h>

selectionsort(int vet[], int n){
    int menor, aux;
    for(int i = 0; i < n-1; i++){
        menor = i;
        for(int j = i+1; j < n; j++){
            printf("\nSelecionado: %d", vet[i]);
            sleep(1);
            printf("\n %d < %d ?", vet[i], vet[j]);
            sleep(1);
            if(vet[menor]>vet[j]){
                printf("\n\nTrocado a posicao de %d por %d\n", vet[i], vet[j]);
                menor = j;
                sleep(1);
            }

        }
        if(i != menor){
            aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
        }
    }
}


int main(){
    int n = 9;
    int vetor[9] = {3,6,9,2,5,7,8,1,4};

    selectionsort(vetor,n);
    printf("\n");
    for(int i = 0;i < n; i++){
        printf("%d -", vetor[i]);
    }

    printf("\n\n\n");

    system("pause");
    return 0;
}
