// ABP.h
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux
{
    TIPOCHAVE chave;
    // Dados armazenados vão aqui
    struct aux *esq, *dir;
    int altura; // Adicionado para suportar árvores AVL
} NO;

typedef NO *PONT;

// Protótipos das funções para árvore AVL
PONT inicializa();
PONT criaNovoNo(TIPOCHAVE ch);
PONT adicionaAVL(PONT raiz, PONT no);
// PONT contem(TIPOCHAVE ch, PONT raiz);
// int numeroNos(PONT raiz);
void exibirArvore(PONT raiz);
// PONT removeNoAVL(PONT raiz, TIPOCHAVE ch);
int altura(PONT no);                  // Função nova para retornar a altura de um nó
PONT rotacaoDireita(PONT no);         // Função nova para rotação à direita
PONT rotacaoEsquerda(PONT no);        // Função nova para rotação à esquerda
PONT rotacaoEsquerdaDireita(PONT no); // Função nova para rotação esquerda-direita
PONT rotacaoDireitaEsquerda(PONT no); // Função nova para rotação direita-esquerda
int max(int a, int b);           // Função auxiliar para calcular o máximo entre dois inteiros
int fatorBalanceamento(PONT no);      // Função nova para calcular o fator de balanceamento de um nó
