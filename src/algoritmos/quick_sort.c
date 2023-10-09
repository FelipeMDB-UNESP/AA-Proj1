#include <stdio.h>

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
void quickSort(int vetor[], int low, int high, int* trocas) {
    if (low < high) {
        // Encontra o índice do pivô, o elemento em vetor[p] agora está no lugar certo
        int pi = partition(vetor, low, high, trocas);

        // Classifica os elementos antes e depois da partição
        quickSort(vetor, low, pi - 1, trocas);
        quickSort(vetor, pi + 1, high, trocas);
    }
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
