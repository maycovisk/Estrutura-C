#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxEnd 3

typedef struct sEndereco{
    char logradouro[100];
    int numero;
    char complemento[30];
    char bairro[30];
    unsigned int cep;
    char cidade[50];
}ENDERECO;

typedef struct sUsuario{
    char nome[100][100];
    int ddd[100];
    int tel[100];
    ENDERECO endereco[maxEnd];
    int contEnd;
} USER;

int main(){
    USER usuarios[100];

    char nome[100][100];
    int ddd[100];
    int tel[100];
    int escolha, contUser = 0, controle;
    char nomeAux[100];



    do{
        printf("======================== MENU ========================\n");
        printf("| 0 ........................................... SAIR |\n");
        printf("| 1 ...................................... ADICIONAR |\n");
        printf("| 2 ........................................ MOSTRAR |\n");
        printf("| 3 ...................................... PESQUISAR |\n");
        printf("| 4 .......................................... SOBRE |\n");
        printf("======================================================\n");
        scanf("%d", &escolha);
        system("cls");
        switch (escolha)
        {
        case 0:
            printf("Obrigado por utilizar o SisteMarques!\n");
            break;
        case 1:
            printf("===================== NOVO CADASTRO ====================\n");
            printf("Entre com as informacoes do novo usuario: \n");
            printf("NOME: ");
            scanf(" %[^\n]", usuarios[contUser].nome);

            printf("DDD: ");
            scanf("%d", &usuarios[contUser].ddd);

            printf("TELEFONE: ");
            scanf("%d", &usuarios[contUser].tel);

            for(int i = 0 ; i < maxEnd; i++){
                printf("===================== ENDERECO ====================\n");
                printf("LOGRADOURO: ");
                scanf(" %[^\n]", usuarios[contUser].endereco[i].logradouro);

                printf("NUMERO: ");
                scanf("%d", &usuarios[contUser].endereco[i].numero);

                printf("COMPLEMENTO: ");
                scanf(" %[^\n]", usuarios[contUser].endereco[i].complemento);

                printf("BAIRRO: ");
                scanf(" %[^\n]", usuarios[contUser].endereco[i].bairro);

                printf("CEP: ");
                scanf("%d", &usuarios[contUser].endereco[i].cep);

                printf("CIDADE: ");
                scanf(" %[^\n]", usuarios[contUser].endereco[i].cidade);

                usuarios[contUser].contEnd = i + 1;

                if(i < maxEnd -1){
                    printf("Digite 1 para cadastrar mais um endereço ou 0 para encerrar...\n");
                    scanf("%d", &controle);

                    if(controle != 1)
                        break;
                }
            }

            contUser++;
            break;
        case 2:
            for (int i = 0; i < contUser;i++)
            {
                printf("===================== USUARIO %d ======================\n", i + 1);
                printf("| NOME: %s\n", usuarios[i].nome);
                printf("| TELEFONE: (%d) %d-%.4d\n", usuarios[i].ddd, usuarios[i].tel[i]/10000, usuarios[i].tel[i]%10000);
                for(int j = 0 ; j < usuarios[i].contEnd; j++){
                    printf("| LOGRADOURO: %s\n",    usuarios[i].endereco[j].logradouro);
                    printf("| NUMERO: %d\n",        usuarios[i].endereco[j].numero);
                    printf("| COMPLEMENTO: %s\n",   usuarios[i].endereco[j].complemento);
                    printf("| BAIRRO: %s\n",        usuarios[i].endereco[j].bairro);
                    printf("| CEP: %d\n",           usuarios[i].endereco[j].cep);
                    printf("| CIDADE: %s\n",        usuarios[i].endereco[j].cidade);
                printf("======================================================\n\n");
                }
            }
            break;
        case 3:
            printf("===================== BUSCAR CADASTRO ===================\n");
            printf("Entre com o nome a ser verificado: ");
            scanf(" %[^\n]", nomeAux);
            for (int i = 0; i < contUser; i++)
            {
                if(strcmp(nome[i], nomeAux) == 0){
                    printf("===================== USUARIO %d ======================\n", i + 1);
                    printf("| NOME: %s\n", nome[i]);
                    printf("| TELEFONE: (%d) %d-%.4d\n", ddd[i], tel[i]/10000, tel[i]%10000);
                    printf("======================================================\n\n");
                    break;
                }
            }
            break;
        case 4:
            printf("======================== SOBRE =======================\n");
            printf("| Este software foi desenvolvido para fins didaticos.|\n");
            printf("| AUTOR: Marques Sousa                               |\n");
            printf("| DATA: 01/09/2022                                   |\n");
            printf("======================================================\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }

    }while(escolha != 0);

    return 0;
}
