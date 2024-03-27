#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

int numMax(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int altura(PONT raiz)
{
    if (!raiz)
        return (-1);
    return (raiz->h);
}

void exibirArvore(PONT raiz)
{
    if (raiz != NULL)
    {
        printf("%i", raiz->chave);
        printf("(");
        exibirArvore(raiz->esq);
        exibirArvore(raiz->dir);
        printf(")");
    }
}

int numeroNos(PONT raiz)
{
    if (!raiz)
        return 0;
    return (numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir));
}

int getBalance(PONT N)
{
    if (N == NULL)
    {
        return 0;
    }
    return altura(N->esq) - altura(N->dir);
}

PONT inicializa()
{
    return (NULL);
}

PONT criaNo(TIPOCHAVE ch)
{
    PONT novoNo =
        (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    novoNo->h = 0;
    return (novoNo);
}

PONT direita(PONT r)
{
    PONT aux = r->esq;
    r->esq = aux->dir;
    aux->dir = r;
    r->h = numMax(altura(r->dir), altura(r->esq)) + 1;
    aux->h = numMax(altura(aux->esq), r->h) + 1;
    return aux;
}

PONT esquerda(PONT r)
{
    PONT aux;
    aux = r->dir;
    r->dir = aux->esq;
    aux->esq = r;
    r->h = numMax(altura(r->dir),
                  altura(r->esq)) +
           1;
    aux->h = numMax(altura(aux->dir),
                    r->h) +
             1;
    return (aux);
}

PONT esquerdaDireita(PONT r)
{
    r->esq = esquerda(r->esq);
    return (direita(r));
}

PONT direitaEsquerda(PONT r)
{
    r->dir = direita(r->dir);
    return (esquerda(r));
}

PONT insere(PONT raiz, TIPOCHAVE ch)
{
    if (!raiz)
        return criaNo(ch);

    if (ch < raiz->chave)
    {
        raiz->esq = insere(raiz->esq, ch);
        if (altura(raiz->esq) - altura(raiz->dir) == 2)
        {
            if (ch < raiz->esq->chave)
                raiz = direita(raiz);
            else
                raiz = esquerdaDireita(raiz);
        }
    }
    else if (ch > raiz->chave)
    {
        raiz->dir = insere(raiz->dir, ch);
        if (altura(raiz->dir) - altura(raiz->esq) == 2)
        {
            if (ch > raiz->dir->chave)
                raiz = esquerda(raiz);
            else
                raiz = direitaEsquerda(raiz);
        }
    }
    raiz->h = numMax(altura(raiz->esq), altura(raiz->dir)) + 1;
    return raiz;
}

// Função para encontrar o nó com o valor mínimo em uma árvore.
PONT minValueNode(PONT node)
{
    PONT current = node;

    // Loop para encontrar a folha mais à esquerda
    while (current->esq != NULL)
    {
        current = current->esq;
    }

    return current;
}

PONT removeNo(PONT raiz, TIPOCHAVE ch)
{
    if (raiz == NULL)
    {
        return raiz; // Elemento não encontrado, retorna a árvore sem alterações
    }

    // Procura o elemento a ser removido
    if (ch < raiz->chave)
    {
        raiz->esq = removeNo(raiz->esq, ch);
    }
    else if (ch > raiz->chave)
    {
        raiz->dir = removeNo(raiz->dir, ch);
    }
    else
    {
        // Nó com apenas um filho ou nenhum filho
        if ((raiz->esq == NULL) || (raiz->dir == NULL))
        {
            PONT temp = raiz->esq ? raiz->esq : raiz->dir;

            // Sem filho
            if (temp == NULL)
            {
                temp = raiz;
                raiz = NULL;
            }
            else
            {                  // Um filho
                *raiz = *temp; // Copia o conteúdo do filho não vazio
            }
            free(temp);
        }
        else
        {
            // Nó com dois filhos: Obtém o sucessor em ordem (menor no lado direito)
            PONT temp = minValueNode(raiz->dir);

            // Copia a chave do sucessor para este nó
            raiz->chave = temp->chave;

            // Deleta o sucessor
            raiz->dir = removeNo(raiz->dir, temp->chave);
        }
    }

    // Se a árvore tinha apenas um nó
    if (raiz == NULL)
    {
        return raiz;
    }

    // Atualiza a altura do nó atual
    raiz->h = 1 + numMax(altura(raiz->esq), altura(raiz->dir));

    // Verifica o balanceamento deste nó ancestral
    int balance = getBalance(raiz);

    // Se este nó se tornar desbalanceado, então há 4 casos

    // Caso Esquerda Esquerda
    if (balance > 1 && getBalance(raiz->esq) >= 0)
    {
        return direita(raiz);
    }

    // Caso Esquerda Direita
    if (balance > 1 && getBalance(raiz->esq) < 0)
    {
        raiz->esq = esquerda(raiz->esq);
        return direita(raiz);
    }

    // Caso Direita Direita
    if (balance < -1 && getBalance(raiz->dir) <= 0)
    {
        return esquerda(raiz);
    }

    // Caso Direita Esquerda
    if (balance < -1 && getBalance(raiz->dir) > 0)
    {
        raiz->dir = direita(raiz->dir);
        return esquerda(raiz);
    }

    return raiz;
}

PONT contem(TIPOCHAVE ch, PONT raiz)
{
    if (raiz == NULL)
        return (NULL);
    if (raiz->chave == ch)
        return (raiz);
    if (raiz->chave > ch)
        return (contem(ch, raiz->esq));
    return (contem(ch, raiz->dir));
}

PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai)
{
    PONT atual = raiz;
    *pai = NULL;
    while (atual)
    {
        if (atual->chave == ch)
            return (atual);
        *pai = atual;
        if (ch < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return (NULL);
}