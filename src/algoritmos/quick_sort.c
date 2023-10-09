#include <stdio.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função que escolhe o último elemento como pivô, coloca o elemento pivô em sua posição correta no vetor
// e coloca todos os elementos menores que o pivô à esquerda e todos os elementos maiores à direita.
int partition(int vetor[], int low, int high, int* trocas) {
    int pivot = vetor[high];  // Pivô
    int i = (low - 1);     // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (vetor[j] <= pivot) {
            i++;    // Incrementa o índice do menor elemento
            swap(&vetor[i], &vetor[j]);
            (*trocas)++; // Incrementa o contador de trocas
        }
    }
    swap(&vetor[i + 1], &vetor[high]);
    (*trocas)++; // Incrementa o contador de trocas
    return (i + 1);
}

// Função principal para executar o Quick Sort
void quickSort(int arr[], int low, int high, int* trocas) {
    clock_t inicio = clock();
    if (low < high) {
        int pi = partition(arr, low, high, trocas);

        quickSort(arr, low, pi - 1, trocas);
        quickSort(arr, pi + 1, high, trocas);
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Quick Sort: %.6f segundos\n", tempo);
}

int main() {
    int vetor[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int trocas = 0; // Inicialize o contador de trocas como 0

    printf("vetor desordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    quickSort(vetor, 0, n - 1, &trocas);

    printf("\nvetor ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nNúmero de trocas: %d\n", trocas); // Imprime o número total de trocas
    return 0;
}
