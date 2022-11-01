#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100

typedef struct vertice {
    int vertice;
    struct vertice* next;
}Vertice;

Vertice* criaVertice(int v) {
    Vertice* newVertice = malloc(sizeof(Vertice));
    newVertice->vertice = v;
    newVertice->next = NULL;
    
    return newVertice;
}

typedef struct grafo {
    int numVertices;
    int* visitados;

    struct vertice** listasAdj;
}Grafo;

Grafo* criaGrafo(int vertices) {
    Grafo* grafo = malloc(sizeof(Grafo));
    grafo->numVertices = vertices;
    grafo->listasAdj = malloc(vertices * sizeof(struct vertice*));
    grafo->visitados = malloc(vertices * sizeof(int));

    int i;
    for (i=0; i<vertices; i++) {
        grafo->listasAdj[i] = NULL;
        grafo->visitados[i] = 0;
    }
    return grafo;
};

void adicionaAresta(Grafo* grafo, int src, int dest) {
    // Adiciona aresta de src a dest
    Vertice* newVertice = criaVertice(dest);
    newVertice->next = grafo->listasAdj[src];
    grafo->listasAdj[src] = newVertice;

    // Adiciona aresta de dest a src
    newVertice = criaVertice(src);
    newVertice->next = grafo->listasAdj[dest];
    grafo->listasAdj[dest] = newVertice;
}

void printGrafo(Grafo* grafo) {
    int v;
    for (v=0; v<grafo->numVertices; v++) {
        struct vertice* temp = grafo->listasAdj[v];
        printf("\nVertice %d: ", v+1);
        while (temp) {
            printf("%d-> ", temp->vertice);
            temp = temp->next;
            }
    }
}

void DFS(Grafo* grafo, int vertice) {
    struct vertice* adjList = grafo->listasAdj[vertice];
    struct vertice* temp = adjList;

    grafo->visitados[vertice] = 1;
    printf("Visitado %d \n", vertice);

    while (temp) {
        int conectado = temp->vertice;

        if (grafo->visitados[conectado] == 0)
            DFS(grafo, conectado);

        temp = temp->next;
    }
}

int main() {
    srand(time(NULL));
    
    Grafo* grafo = criaGrafo(TAMANHO);

    for (int i=1; i<TAMANHO; i++) {
        int src = 1 + rand() % 1000;
        int dest = 1 + rand() % 1000;
        criaVertice(1 + rand() % 1000);
    }

    for (int i=1; i<TAMANHO; i++) {
        int src = 1 + rand() % 1000;
        int dest = 1 + rand() % 1000;
        adicionaAresta(grafo, src, dest);
    }

    printf("\n========= O Grafo =========");
    printGrafo(grafo);
    printf("\n");

    printf("\n========= DFS =========\n");
    DFS(grafo, 1 + rand() % 1000);

    return 0;
}
