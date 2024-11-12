#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int opcao, opcao1, i, totalUsuarios = 0;

    struct referencia {
        char nome0[50], nome1[50];
    } CA[600];

    do {
        system("cls");
        printf("\t\t\t SEJA BEM-VINDO AO MENU, SELECIONE A SUA OPÇÃO ABAIXO \n");
        printf("[1] - CADASTRAR NOVO USUÁRIO \n");
        printf("[2] - EXIBIR USUÁRIOS CADASTRADOS \n");
        printf("[3] - ALTERAR DADOS DE UM USUÁRIO \n");
        printf("[4] - REMOVER UM USUÁRIO \n");
        printf("[5] - SAIR\n");
        printf("-------------------------------------------------------------------------------- \n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1: 
            system("cls");
            int novosUsuarios;
            printf("Quantos usuários você gostaria de cadastrar? \n");
            scanf("%d", &novosUsuarios);

            for (i = totalUsuarios; i < totalUsuarios + novosUsuarios; i++) {
                system("cls");
                printf("Qual o nome do usuário? (Máximo 50 caracteres) \n");
                while (getchar() != '\n'); 
                scanf("%[^\n]s", CA[i].nome0);
                printf("Qual a senha do usuário? (Máximo 50 caracteres) \n");
                while (getchar() != '\n'); 
                scanf("%[^\n]s", CA[i].nome1);
                printf("Usuário %d cadastrado com sucesso.\n", i + 1);
                system("pause");
            }
            totalUsuarios += novosUsuarios; 
            break;

       case 2: 
            system("cls");
            if (totalUsuarios == 0) {
                printf("Nenhum usuário cadastrado.\n");
            } else {
                printf("\t\t\t EXIBINDO OS USUÁRIOS CADASTRADOS: \n");
                printf("-------------------------------\n");
                for (i = 0; i < totalUsuarios; i++) {
                    printf("Usuário [%d]\n", i + 1);
                    printf("Nome: %s\n", CA[i].nome0);
                    printf("Senha: %s\n", CA[i].nome1);
                    printf("-------------------------------\n");
                }
            }
            printf("Pressione qualquer tecla para voltar ao menu...\n");
            while (getchar() != '\n'); 
            getchar();
            break;

        case 3: 
            system("cls");
            if (totalUsuarios == 0) {
                printf("Nenhum usuário cadastrado para editar.\n");
            } else {
                printf("Qual usuário você gostaria de editar? (lista abaixo)\n");
                printf("-------------------------------\n");
                for (i = 0; i < totalUsuarios; i++) {
                    printf("[%d] - Nome: %s\n", i + 1, CA[i].nome0);
                }
                printf("-------------------------------\n");

                int usuarioEscolhido;
                printf("Digite o numero do usuário que deseja editar: ");
                scanf("%d", &usuarioEscolhido);

                if (usuarioEscolhido < 1 || usuarioEscolhido > totalUsuarios) {
                    printf("Usuário invalido.\n");
                } else {
                    usuarioEscolhido--; 
                    system("cls");
                    printf("Qual informação do usuário deseja alterar? \n");
                    printf("[1] - Nome do usuário \n");
                    printf("[2] - Senha do usuário \n");
                    scanf("%d", &opcao1);

                    switch (opcao1) {
                    case 1: 
                        printf("Digite o novo nome para o usuário %d: ", usuarioEscolhido + 1);
                        while (getchar() != '\n'); 
                        scanf("%[^\n]s", CA[usuarioEscolhido].nome0);
                        printf("Nome atualizado com sucesso.\n");
                        break;

                    case 2: 
                        printf("Digite a nova senha para o usuário %d: ", usuarioEscolhido + 1);
                        while (getchar() != '\n'); 
                        scanf("%[^\n]s", CA[usuarioEscolhido].nome1);
                        printf("Senha atualizada com sucesso.\n");
                        break;

                    default:
                        printf("Opção invalida.\n");
                        break;
                    }
                }
            }
            system("pause");
            break;

        case 4: 
            system("cls");
            if (totalUsuarios == 0) {
                printf("Nenhum usuário cadastrado para remover.\n");
            } else {
                printf("Qual usuário você gostaria de remover? (lista abaixo)\n");
                printf("-------------------------------\n");
                for (i = 0; i < totalUsuarios; i++) {
                    printf("[%d] - Nome: %s\n", i + 1, CA[i].nome0);
                }
                printf("-------------------------------\n");

                int usuarioRemover;
                printf("Digite o numero do usuário que deseja remover: ");
                scanf("%d", &usuarioRemover);

                if (usuarioRemover < 1 || usuarioRemover > totalUsuarios) {
                    printf("Usuário invalido.\n");
                } else {
                    usuarioRemover--; 

                    for (i = usuarioRemover; i < totalUsuarios - 1; i++) {
                        CA[i] = CA[i + 1]; 
                    }

                    totalUsuarios--; 
                    printf("Usuário removido com sucesso.\n");
                }
            }
            system("pause");
            break;

        case 5: 
            printf("Saindo do programa.\n");
            break;

        default:
            printf("Opção invalida! Selecione uma opção valida.\n");
            system("pause");
            break;
        }

    } while (opcao != 5);

    return 0;
}
