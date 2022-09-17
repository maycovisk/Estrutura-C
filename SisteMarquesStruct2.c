#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxEnd 3   //Maximo de enderecos por usuario.
#define maxTam 100 //Maximo de tamanho

typedef struct sEndereco{
    char logradouro[100];
    int numero;
    char complemento[30];
    char bairro[30];
    int cep;
    char cidade[60];
}ENDERECO;

typedef struct sUsuario{
    char nome[100];
    int ddd;
    int tel;
    ENDERECO endereco[maxEnd];
    int contEnd;
}USER;

int menu(){
    int escolha;
    printf("======================== MENU ========================\n");
    printf("| 0 ........................................... SAIR |\n");
    printf("| 1 ...................................... ADICIONAR |\n");
    printf("| 2 ........................................ MOSTRAR |\n");
    printf("| 3 ...................................... PESQUISAR |\n");
    printf("| 4 ......................................... EDITAR |\n");
    printf("| 5 ........................................ EXCLUIR |\n");
    printf("| 6 .......................................... SOBRE |\n");
    printf("======================================================\n");
    scanf("%d", &escolha);
    system("cls");
    return escolha;
}

int insert(USER usuarios[], int contUser){
    int controle = 0;
    printf("===================== NOVO CADASTRO ====================\n");
    printf("Entre com as informacoes do novo usuario: \n");
    printf("NOME: ");
    scanf(" %[^\n]", usuarios[contUser].nome);

    printf("DDD: ");
    scanf("%d", &usuarios[contUser].ddd);

    printf("TELEFONE: ");
    scanf("%d", &usuarios[contUser].tel);

    for(int i = 0; i < maxEnd; i++){
        printf("=========== Endereco ===========\n");
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

        if( i < maxEnd - 1){
            printf("Digite 1 para cadastrar + 1 endereco ou zero pra encerrar: \n");
            scanf("%d", &controle);

            if(controle != 1)
                break;
        }
    }
    return 1;
}

void printAdress(USER usuarios[], int ind){
    for(int j = 0; j < usuarios[ind].contEnd; j++){
        printf("| LOGRADOURO: %s\n",  usuarios[ind].endereco[j].logradouro);
        printf("| NUMERO: %d\n",      usuarios[ind].endereco[j].numero);
        printf("| COMPLEMENTO: %s\n", usuarios[ind].endereco[j].complemento);
        printf("| BAIRRO: %s\n",      usuarios[ind].endereco[j].bairro);
        printf("| CEP: %d\n",         usuarios[ind].endereco[j].cep);
        printf("| CIDADE: %s\n",      usuarios[ind].endereco[j].cidade);
    }
}

void printAdressEdit(USER usuarios,int contEnd, ind){
    for (int i = 0; i < contUser; i++){
        for(int j = 0, n =1; j < usuarios[i].contEnd; j++, n++){
                printf("| LOGRADOURO %d: %s\n", n, usuarios[i].endereco[j].logradouro);
        }
    }
}

void search(USER usuarios[], int contUser, int caso){
    char nomeAux[100];
    if(contUser == 0)
        printf("CADASTRO VAZIO!!!\n");
    else{
        if(caso == 3){
            printf("===================== BUSCAR CADASTRO ===================\n");
            printf("Entre com o nome a ser verificado: ");
            scanf(" %[^\n]", nomeAux);
        }
    }

    for (int i = 0; i < contUser; i++){
        if(caso == 2 || strcmp(usuarios[i].nome, nomeAux) == 0){
            printf("===================== USUARIO %d ======================\n", i + 1);
            printf("| NOME: %s\n", usuarios[i].nome);
            printf("| TELEFONE: (%d) %d-%.4d\n", usuarios[i].ddd, usuarios[i].tel/10000, usuarios[i].tel%10000);

            printAdress(usuarios, i);
        printf("======================================================\n", i + 1);
        }
    }
}

void edit(USER usuarios[], int contUser){
    char nomeAux;
    int opEdit, opEnd;
    if(contUser == 0)
        printf("CADASTRO VAZIO!!!\n");
    else{
        printf("===================== EDITAR CADASTRO ===================\n");
        printf("Entre com o nome a ser editado: ");
        scanf(" %[^\n]", nomeAux);
        for (int i = 0; i < contUser; i++)
        {
            if(strcmp(usuarios[i].nome, nomeAux) == 0){
                do{
                    printf("| 0 ........................................... SAIR |\n");
                    printf("| 1 .................................... EDITAR NOME |\n");
                    printf("| 2 ..................................... EDITAR DDD |\n");
                    printf("| 3 ................................ EDITAR TELEFONE |\n");
                    printf("| 4 .............................. EDITAR LOGRADOURO |\n");
                    printf("| 5 .................................. EDITAR NUMERO |\n");
                    printf("| 6 ............................. EDITAR COMPLEMENTO |\n");
                    printf("| 7 .................................. EDITAR BAIRRO |\n");
                    printf("| 8 ..................................... EDITAR CEP |\n");
                    printf("| 9 .................................. EDITAR CIDADE |\n");

                    scanf("%d", &opEdit);

                    switch (opEdit)
                    {
                        case 0:
                            break;
                        case 1:
                            printf("NOME ATUAL: %s\n", usuarios[i].nome);
                            printf("Digite o novo nome: \n");
                            scanf(" %[^\n]", usuarios[i].nome);
                            break;

                        case 2:
                            printf("DDD ATUAL: %s\n", usuarios[i].ddd   );
                            printf("Digite o novo DDD: \n");
                            scanf("%d", &usuarios[i].ddd);
                            break;

                        case 3:
                            printf("TELEFONE ATUAL: %s\n", usuarios[i].tel);
                            printf("Digite o novo telefone: \n");
                            scanf("%d", &usuarios[i].tel);
                            break;

                        case 4:
                            printAdress(usuarios, i);
                            for (int i = 0; i < contUser; i++){
                                for(int j = 0, n =1; j < usuarios[i].contEnd; j++, n++){
                                        printf("| LOGRADOURO %d: %s\n", n, usuarios[i].endereco[j].logradouro);
                                }
                            }
                            printf("| Digite o numero do logradouro que deseja editar: |\n");
                            scanf("%d", &opEnd);
                            printf("LOGRADOURO %d ATUAL: %s\n", opEnd, usuarios[i].endereco[opEnd-1].logradouro);
                            printf("Digite o novo logradouro: ");
                            scanf(" %[^\n]", usuarios[i].endereco[opEnd-1].logradouro);
                            break;

                        case 5:
                            for (int i = 0; i < contUser; i++){
                                for(int j = 0, n =1; j < usuarios[i].contEnd; j++, n++){
                                        printf("| NUMERO %d: %d\n", n, usuarios[i].endereco[j].numero);
                                }
                            }
                            printf("| Digite o numero do numero que deseja editar: |\n");
                            scanf("%d", &opEnd);
                            printf("NUMERO %d ATUAL: %d\n", opEnd, usuarios[i].endereco[opEnd-1].numero);
                            printf("Digite o novo numero: ");
                            scanf("%d", &usuarios[i].endereco[opEnd-1].numero);
                            break;

                        case 6:
                            for (int i = 0; i < contUser; i++){
                                for(int j = 0, n =1; j < usuarios[i].contEnd; j++, n++){
                                        printf("| COMPLEMENTO %d: %s\n", n, usuarios[i].endereco[j].complemento);
                                }
                            }
                            printf("| Digite o numero do complemento que deseja editar: |\n");
                            scanf("%d", &opEnd);
                            printf("COMPLEMENTO %d ATUAL: %s\n", opEnd, usuarios[i].endereco[opEnd-1].complemento);
                            printf("Digite o novo complemento: ");
                            scanf(" %[^\n]", usuarios[i].endereco[opEnd-1].complemento);
                            break;

                        case 7:
                            for (int i = 0; i < contUser; i++){
                                for(int j = 0, n =1; j < usuarios[i].contEnd; j++, n++){
                                        printf("| BAIRRO %d: %s\n", n, usuarios[i].endereco[j].bairro);
                                }
                            }
                            printf("| Digite o numero do bairro  que deseja editar: |\n");
                            scanf("%d", &opEnd);
                            printf("LOGRADOURO %d ATUAL: %s\n", opEnd, usuarios[i].endereco[opEnd-1].bairro);
                            printf("Digite o novo bairro: ");
                            scanf(" %[^\n]", usuarios[i].endereco[opEnd-1].bairro);
                            break;

                        case 8:
                            for (int i = 0; i < contUser; i++){
                                for(int j = 0, n =1; j < usuarios[i].contEnd; j++, n++){
                                        printf("| CEP %d: %d\n", n, usuarios[i].endereco[j].cep);
                                }
                            }
                            printf("| Digite o numero do cep que deseja editar: |\n");
                            scanf("%d", &opEnd);
                            printf("CEP %d ATUAL: %d\n", opEnd, usuarios[i].endereco[opEnd-1].cep);
                            printf("Digite o novo cep: ");
                            scanf("%d", &usuarios[i].endereco[opEnd-1].cep);
                            break;

                        case 9:
                            for (int i = 0; i < contUser; i++){
                                for(int j = 0, n =1; j < usuarios[i].contEnd; j++, n++){
                                        printf("| CIDADE %d: %s\n", n, usuarios[i].endereco[j].cidade);
                                }
                            }
                            printf("| Digite o numero da cidade que deseja editar: |\n");
                            scanf("%d", &opEnd);
                            printf("LOGRADOURO %d ATUAL: %s\n", opEnd, usuarios[i].endereco[opEnd-1].cidade);
                            printf("Digite a nova cidade: ");
                            scanf(" %[^\n]", usuarios[i].endereco[opEnd-1].cidade);
                            break;

                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                }while(opEdit != 0);

                break;
            }
        }
    }


}

int main(){
    USER usuarios[100];

    char nome[100][100];
    int ddd[100];
    int tel[100];
    int escolha, contUser = 0, opEdit, controle, opEnd;
    char nomeAux[100];


    do{
        escolha = menu();
        switch (escolha)
        {
        case 0:
            printf("Obrigado por utilizar o SisteMarques!\n");
            break;
        case 1:
            if(insert(usuarios, contUser) == 1){
                printf("CADASTRO REALIZADO COM SUCESSO!\n");
                contUser++;
            }else{
                printf("PROBLEMA: CADASTRO NAO CONCLUIDO!\n");
            }
            break;
        case 2:
            search(usuarios, contUser, escolha);
            break;
        case 3:
            search(usuarios, contUser, escolha);
            break;
        case 4:
            edit(usuarios, contUser);
            break;
        case 5:
            if(contUser == 0)
                printf("CADASTRO VAZIO!!!\n");
            else{
                printf("===================== EXCLUIR CADASTRO ===================\n");
                printf("Entre com o nome a ser excluido: ");
                scanf(" %[^\n]", nomeAux);
                for (int i = 0; i < contUser; i++)
                {
                    if(strcmp(usuarios[i].nome, nomeAux) == 0){
                        strcpy(usuarios[i].nome, usuarios[contUser - 1].nome);
                        usuarios[i].ddd = usuarios[contUser - 1].ddd;
                        usuarios[i].tel = usuarios[contUser - 1].tel;

                        for(int j = 0; j < usuarios[contUser - 1].contEnd; j++){
                            strcpy(usuarios[i].endereco[j].logradouro, usuarios[contUser - 1].endereco[contUser  - 1].logradouro);
                            usuarios[i].endereco[j].numero = usuarios[contUser - 1].endereco[j].numero;
                            strcpy(usuarios[i].endereco[j].complemento, usuarios[contUser - 1].endereco[contUser  - 1].complemento);
                            strcpy(usuarios[i].endereco[j].bairro, usuarios[contUser - 1].endereco[contUser  - 1].bairro);
                            usuarios[i].endereco[j].cep = usuarios[contUser - 1].endereco[j].cep;
                            strcpy(usuarios[i].endereco[j].cidade, usuarios[contUser - 1].endereco[contUser  - 1].cidade);
                        }
                        usuarios[i].contEnd = usuarios[contUser - 1].contEnd;
                        contUser--;
                        printf("CADASTRO EXCLUIDO COM SUCESSO!!!\n");
                        break;
                    }
                }
            }
            break;
        case 6:
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
