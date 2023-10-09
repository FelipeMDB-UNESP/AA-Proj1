#include <stdio.h>

// Função para ajustar um heap máximo
void maxHeapify(int vetor[], int n, int i, int *trocas) {
    int maior = i;    // Inicializa o maior como a raiz
    int esquerda = 2 * i + 1; // Índice do filho esquerdo
    int direita = 2 * i + 2;  // Índice do filho direito

    // Se o filho esquerdo for maior que a raiz
    if (esquerda < n && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
    }

    // Se o filho direito for maior que a raiz
    if (direita < n && vetor[direita] > vetor[maior]) {
        maior = direita;
    }

    // Se o maior não for a raiz
    if (maior != i) {
        // Troca a raiz com o maior elemento
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;
        (*trocas)++; // Incrementa o contador de trocas

        // Chama recursivamente a função em subárvore
        maxHeapify(vetor, n, maior, trocas);
    }
}

// Função para realizar o Heap Sort
void heapSort(int vetor[], int n) {
    int trocas = 0; // Inicialize o contador de trocas como 0

    // Constrói o heap máximo (revetoranja o vetor)
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(vetor, n, i, &trocas);
    }

    // Extrai elementos um por um do heap
    for (int i = n - 1; i >= 0; i--) {
        // Move a raiz atual para o final
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        trocas++; // Incrementa o contador de trocas

        // Chama maxHeapify no heap reduzido
        maxHeapify(vetor, i, 0, &trocas);
    }

    printf("Número de trocas: %d\n", trocas); // Imprime o número total de trocas
}

int main() {
    int vetor[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor desordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    heapSort(vetor, n);

    printf("\nVetor ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
