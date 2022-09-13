/* Andre Vinicius Zicka Schmidt - PEDA 2022.2 */
/* Trabalho 06 - Arvores Binarias de Busca */
/* Arvores binarias de busca sao arvores que possuem no maximo dois
filhos de tal forma que o valor utilizado como chave, ou indice da 
arvore deve seguir a seguinte regra:
    O indice do filho a esquerda sera menor que o indice do vertice
    pai (raiz) e o indice deste vertice pai sera menor que o indice
    do filho a direita.
A arovre devera ser gerada de forma aleatoria e deve possuir um numero
de vertices aleatoriamente selecionado entre 10 e 26 vertices. Para
criar esta arvore voce ira criar um array capaz de armazenar uma
quantidade de itens equivalente ao numero de vertices da arvore que
sera gerada e preencher estes vertices com valores aleatorios entre 1
e 1000. Este array sera usado para montar a arvore binaria de busca.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Definicao da estrutura No */
typedef struct vertice {
    int dado;
    struct vertice *esquerda;
    struct vertice *direita;
} vertice;

/* Prototipos das funcoes para recursividade */
vertice *minimo(vertice *);
vertice *maximo(vertice *);
vertice *inserirVertice(vertice *, int);
vertice *apagarVertice(vertice *, int);
vertice *buscarVertice(vertice *, int);
void displayInOrder(vertice *);
void displayPreOrder(vertice *);
void displayPostOrder(vertice *);

/* Funcao Minimo - Encontra o menor vertice */
vertice *minimo(vertice *node) {
    if(node==NULL)
        return NULL;
    if(node->esquerda)
        return minimo(node->esquerda);
    else
        return node;
} /* Fim minimo */

/* Funcao Maximo - Encontra o maior vertice */
vertice *maximo(vertice *node) {
    if(node==NULL)
        return NULL;
    if(node->direita)
        return maximo(node->direita);
    else
        return node;
} /* Fim maximo */

/* Funcao de Insercao - Insere um no na estrutura da arvore */
vertice *inserirVertice(vertice *node, int dado) {
    if(node==NULL) {
        vertice *temp;
        temp = (vertice *)malloc(sizeof(vertice));
        temp->dado = dado;
        temp->esquerda = NULL;
        temp->direita = NULL;
        return temp;
    }
    if(dado > (node->dado))
        node->direita = inserirVertice(node->direita, dado);
    else if(dado < (node->dado))
        node->esquerda = inserirVertice(node->esquerda, dado);
    
    return node;
} /* Fim insercao */

/* Funcao de Remocao - Apaga um no especifico */
vertice *apagarVertice(vertice *node, int dado) {
    vertice *temp;

    if(node==NULL)
        printf("\nEste no nao existe!\n");
    else if(dado < node->dado)
        node->esquerda = apagarVertice(node->esquerda, dado);
    else if(dado > node->dado)
        node->direita = apagarVertice(node->direita, dado);
    else {
        if(node->direita && node->esquerda) {
            temp = minimo(node->direita);
            node->dado = temp->dado;
            node->direita = apagarVertice(node->direita, temp->dado);
        }
        else {
            temp = node;

            if(node->esquerda == NULL)
                node = node->direita;
            else if(node->direita == NULL)
                node = node->esquerda;

            free(temp);
        }
    }
    return node;
} /* Fim remocao */

/* Funcao de Busca - Busca na arvore um dado especifico */
vertice *buscarVertice(vertice *node, int dado) {
    if(node==NULL)
        return NULL;
    if(dado > node->dado)
        return buscarVertice(node->direita, dado);
    else if(dado < node->dado)
        return buscarVertice(node->esquerda, dado);
    else
        return node;
} /* Fim busca */


/* FUNCOES DE TRANSVERSALIDADE */
/* Display In-order */
void displayInOrder(vertice *node) {
    if(node==NULL)
        return;
    displayInOrder(node->esquerda);
    printf("%d, ", node->dado);
    displayInOrder(node->direita);
} /* Fim In-order */

/* Display Pre-order */
void displayPreOrder(vertice *node) {
    if(node==NULL)
        return;
    printf("%d, ", node->dado);
    displayPreOrder(node->esquerda);
    displayPreOrder(node->direita);
} /* Fim Pre-order */

/* Display Post-order */
void displayPostOrder(vertice *node) {
    if(node==NULL)
        return;
    displayPreOrder(node->direita);
    printf("%d, ", node->dado);
    displayPreOrder(node->esquerda);
}

int main() {
    printf("\n\n===== Andre Vinicius Zicka Schmidt - PEDA 2022.2 =====");
    printf("\n------ Trabalho 06 - Arvores Binarias de Busca ------");
    printf("\n~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");


    srand(time(NULL));  // Seed pro gerador de numeros pseudo-aleatorios
    int numVertices = 10 + rand()%16;  // Numeros entre 10 e 26
    int valores[numVertices];  // Array para armazenar os valores
    printf("\nNumero de vertices sorteado: %d", numVertices);

    /* a) Impressao do array gerado no formato [a, b, c, d, e, ...] */
    printf("\n\na) Array gerado: [");
    for(int i=0; i<numVertices; i++) {
        valores[i] = 1 + rand()%1000;  // Valores entre 1 e 1000
        if(i !=numVertices-1)
            printf("%d, ", valores[i]);
        else
            printf("%d]", valores[i]);
    }
    /* Fim a) */

    vertice *arvore = NULL;
    int node;
    for(int j=0; j<numVertices; j++)
        arvore = inserirVertice(arvore, valores[j]);

    /* b) Impressao da arvore em ASCII com tabulacao */
    printf("\n\nb) NAO IMPLEMENTADO :(");

    /* c) Impressao dos valores usando transversalidade */
    printf("\n\nc) Impressao dos valores usando transversalidade");
    /* c) i. In-order */
    printf("\nIn-order: {");
    displayInOrder(arvore);
    printf("}");

    /* c) ii. Pre-order */
    printf("\nPre-order: {");
    displayPreOrder(arvore);
    printf("}");

    /* c) iii. Post-order */
    printf("\nPost-order: {");
    displayPostOrder(arvore);
    printf("}");

    /* d) Impressao dos valores de todas as folhas no formato [a, b, c, ...] */
    printf("\n\nd) NAO IMPLEMENTADO :(");
    
    /* e) Lista do resultado da busca de 10 valores aleatorios entre 
        300 e 575, informando se estao presentes ou ausentes na arvore. */
    printf("\n\ne) Resultados de busca de valores aleatorios:");
    vertice *encontrado;
    for(int k=0; k<10; k++) {
        int numSorteado = 300 + rand()%475;
        // Se o valor for encontrado, retorna o vertice em que foi encontrado
        encontrado = buscarVertice(arvore, numSorteado);
        if(encontrado==NULL)
            printf("\nValor gerado: %d;  Diagnostico: Ausente", numSorteado);
        else
            printf("\nValor gerado: %d;  Diagnostico: Presente", numSorteado);
    }

    printf("\n\n~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
    return 0;
}
