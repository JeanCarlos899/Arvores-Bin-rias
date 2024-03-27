#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

int main()
{
    PONT raiz = inicializa();
    int opcao, chave;

    do
    {
        printf("\nMenu de Operações - Árvore AVL\n");
        printf("1. Inserir chave\n");
        printf("2. Exibir árvore (simplificado)\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite a chave a ser inserida: ");
            scanf("%d", &chave);
            raiz = adicionaAVL(raiz, criaNovoNo(chave));
            printf("Chave %d inserida.\n", chave);
            break;

        case 2:
            printf("Árvore AVL (Formato Simplificado):\n");
            exibirArvore(raiz); // Esta função precisa ser implementada de acordo com a estrutura da sua árvore
            break;

        case 3:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}
