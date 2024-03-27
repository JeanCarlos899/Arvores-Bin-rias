#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

// Função que inicializa a árvore;
PONT inicializa()
{
    return (NULL);
}

// Função que cria um novo nó
PONT criaNovoNo(TIPOCHAVE ch)
{
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    novoNo->altura = 0; // Inicializa a altura do nó como 0
    return (novoNo);
}

// Funções auxiliares (altura, max, rotações, fatorBalanceamento) serão implementadas aqui
// Continuação de ABP.c

// Função para calcular a altura de um nó
int altura(PONT no)
{
    if (no == NULL)
        return -1;
    return no->altura;
}

// Função para retornar o maior entre dois números
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Rotação simples à direita
PONT rotacaoDireita(PONT r)
{
    PONT noEsq = r->esq;
    r->esq = noEsq->dir;
    noEsq->dir = r;
    r->altura = max(altura(r->esq), altura(r->dir)) + 1;
    noEsq->altura = max(altura(noEsq->esq), r->altura) + 1;
    return noEsq;
}

// Rotação simples à esquerda
PONT rotacaoEsquerda(PONT r)
{
    PONT noDir = r->dir;
    r->dir = noDir->esq;
    noDir->esq = r;
    r->altura = max(altura(r->esq), altura(r->dir)) + 1;
    noDir->altura = max(r->altura, altura(noDir->dir)) + 1;
    return noDir;
}

// Rotação esquerda-direita
PONT rotacaoEsquerdaDireita(PONT r)
{
    r->esq = rotacaoEsquerda(r->esq);
    return rotacaoDireita(r);
}

// Rotação direita-esquerda
PONT rotacaoDireitaEsquerda(PONT r)
{
    r->dir = rotacaoDireita(r->dir);
    return rotacaoEsquerda(r);
}

// Calcula o fator de balanceamento de um nó
int fatorBalanceamento(PONT no)
{
    return altura(no->esq) - altura(no->dir);
}

// Insere um nó na árvore AVL e a balanceia
PONT adicionaAVL(PONT raiz, PONT no)
{
    if (raiz == NULL)
        return no;

    if (no->chave < raiz->chave)
    {
        raiz->esq = adicionaAVL(raiz->esq, no);
    }
    else if (no->chave > raiz->chave)
    {
        raiz->dir = adicionaAVL(raiz->dir, no);
    }
    else
    {
        // Chave duplicada; não faz nada
        return raiz;
    }

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int fb = fatorBalanceamento(raiz);

    // Rotações para balancear a árvore
    if (fb > 1 && no->chave < raiz->esq->chave)
    {
        return rotacaoDireita(raiz);
    }
    if (fb < -1 && no->chave > raiz->dir->chave)
    {
        return rotacaoEsquerda(raiz);
    }
    if (fb > 1 && no->chave > raiz->esq->chave)
    {
        return rotacaoEsquerdaDireita(raiz);
    }
    if (fb < -1 && no->chave < raiz->dir->chave)
    {
        return rotacaoDireitaEsquerda(raiz);
    }

    return raiz;
}

// Esta função deve ser adicionada ao ABP.c
void exibirArvore(PONT raiz)
{

}
