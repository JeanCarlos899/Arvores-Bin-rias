#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int boolean;
typedef int TIPOCHAVE;

typedef struct aux
{
    TIPOCHAVE chave;
    struct aux *esq;
    struct aux *dir;
    int h;
} NO, *PONT;

void exibirArvore(PONT raiz);
int numMax(int a, int b);
int altura(PONT raiz);
int numeroNos(PONT raiz);

PONT inicializa();
PONT criaNo(TIPOCHAVE ch);
PONT direita(PONT r);
PONT esquerda(PONT r);
PONT esquerdaDireita(PONT r);
PONT direitaEsquerda(PONT r);
PONT insere(PONT raiz, TIPOCHAVE ch);
PONT minValueNode(PONT node);
PONT removeNo(PONT raiz, TIPOCHAVE ch);
PONT contem(TIPOCHAVE ch, PONT raiz);
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai);
