//LACO DE REPETICAO
#include <stdio.h>

/*sintaxe FOR

for( INICIALIZACAO ; CRITERIO DE PARADA ; INCREMENTO OU DECREMENTO ) {
}
*/

int main (){
    int i, j;

    for(i = 3; i >= 0; i--){
        for(j = 3; j >= 0; j--){
            printf("*\t");
        }
        printf("\n");
    }
    return 0;
}
