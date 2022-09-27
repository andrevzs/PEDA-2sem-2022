/* Andre Vinicius Zicka Schmidt - PEDA 2022.2 */
/* Trabalho 07 - Arvores Heap */

/* ENUNCIADO
- Construir um heap (binario, max-heap);
- Criar metodos para:
    - criar a árvore e buscar valores na arvore
- Para testar usar um array com no minimo 500 itens aleatorios
*/
#include <stdio.h>
#include <time.h>

#define TAMANHO_ARRAY 500


void heapify(int arr[], int n, int i);
void trocar(int *a, int *b);

void heapify(int arr[], int n, int i) {
    int maior = i;
    int filhoEsquerdo = 2*i + 1;
    int filhoDireito = 2*i + 2;

    if (filhoEsquerdo < n && arr[filhoEsquerdo] > arr[maior])
        maior = filhoEsquerdo;
    if (filhoDireito < n && arr[filhoDireito] > arr[maior])
        maior = filhoDireito;
    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        heapify(arr, n, maior);
    }
        
}

void criaHeap(int arr[], int n) {
    int ultimoNoNaoFolha = (n/2) - 1;

    for (int i=ultimoNoNaoFolha; i>-0; i--)
        heapify(arr, n, i);
}

void trocar(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void imprimirArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void buscar(int numero, int arr[], int n) {
    for (int i=0; i<n; i++) {
        if (arr[i]==numero) {
            printf("\nNumero encontrado!");
            return;
        }
    }
    printf("\nNumero nao encontrado...");
}

int main() {
    srand(time(NULL));  // Seed para gerar numeros pseudo-aleatorios

    int arr[TAMANHO_ARRAY];

    // printf("\n\nArray gerado: [");
    for (int i=0; i<TAMANHO_ARRAY; i++) {
        arr[i] = 1 + rand()%100; 
        // Range entre 1 e 100 definido arbitrariamente, ja que nao foi especificado range
    }


    printf("Array gerado: ");
    imprimirArray(arr, TAMANHO_ARRAY);
    
    criaHeap(arr, TAMANHO_ARRAY);
    printf("\n");
    
    printf("Heap criado: ");
    imprimirArray(arr, TAMANHO_ARRAY);

    int numero = 1 + rand()%100;
    printf("\nNumero sorteado: %d", numero);
    buscar(numero, arr, TAMANHO_ARRAY);

    return 0;
}
