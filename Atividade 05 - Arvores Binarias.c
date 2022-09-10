#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int conteudo;
    struct no *esquerda, *direita;
}No;

typedef struct {
    No *raiz;
}ArvB;

/* Definicao dos prototipos das funcoes devido a recursividade */
void inserirEsquerda(No *no, int valor);
void inserirDireita(No *no, int valor);
void inserir(ArvB *arv, int valor);
void imprimir(No *raiz);

/* Funcoes de insercao */
void inserirEsquerda(No *no, int valor) {
    if(no->esquerda == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita  = NULL;
        no->esquerda = novo;
    }
    else {
        if(valor < no->esquerda->conteudo)
            inserirEsquerda(no->esquerda, valor);
        if(valor > no->esquerda->conteudo)
            inserirDireita(no->esquerda, valor);
    }
}

void inserirDireita(No *no, int valor) {
    if(no->direita == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita  = NULL;
        no->direita = novo;
    }
    else {
        if(valor > no->direita->conteudo)
            inserirDireita(no->direita, valor);
        if(valor < no->direita->conteudo)
            inserirEsquerda(no->direita, valor);
    }
}

void inserir(ArvB *arv, int valor) {
    if(arv->raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita  = NULL;
        arv->raiz = novo;
    }
    else {
        if(valor < arv->raiz->conteudo) {
            inserirEsquerda(arv->raiz, valor);
            //printf("\nInserido esquerda: %d", valor);
        }
        if(valor > arv->raiz->conteudo) {
            inserirDireita(arv->raiz, valor);
            //printf("\nInserido direita: %d", valor);
        }
    }
}
/* Fim funcoes de insercao */

/* Funcao de impressao */
void imprimir(No *raiz) {
    if(raiz != NULL) {
        printf("\n%d", raiz->conteudo);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}
/* Fim funcao de impressao */

int main() {
    /* Calculo do numero de vertices da arvore */
    int numVertices;
    int min = 5, max = 6;
    
    srand(time(NULL));
    numVertices = (rand() % (max-min + 1)) + min;
    
    printf("\nNumero de vertices sorteado: %d\n", numVertices);
    /* Fim calculo de vertices */

    /* Criacao e preenchimento do array */
    int arrayValores[numVertices];

    for(int i=0; i <numVertices; i++) {
        min = 1, max = 1000;
        int item = (rand() % (max-min + 1)) + min;
        arrayValores[i] = item;
    }
    /* Fim criacao do array */

    /* a) Impressao do array gerado */
    printf("\na) Array gerado: [ ");
    for(int i=0; i<numVertices; i++) {
        printf("%d ", arrayValores[i]);
    }
    printf("]\n");
    /* Fim a) */

    /* Criacao da arvore */
    ArvB arv;
    arv.raiz = NULL;

    for(int i=0; i <numVertices; i++) {
        inserir(&arv, arrayValores[i]);
    }
    /* Fim criacao da arvore */

    /* b) Impressao da arvore em ASCII */
    printf("\nb) Impressao da arvore: ");
    // printf("\n%d", arv.raiz->conteudo);
    imprimir(arv.raiz);
    /* Fim b) */

    /* c) Impressao com transversalidade */
    /* Fim c) */

    /* d) Impressao folhas */
    /* Fim d) */

    /* e) Busca de 10 valores */
    /* Fim e) */

    return 0;
}
