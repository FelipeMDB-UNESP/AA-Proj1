#include <stdio.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função que escolhe o último elemento como pivô, coloca o elemento pivô em sua posição correta no array
// e coloca todos os elementos menores que o pivô à esquerda e todos os elementos maiores à direita.
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivô
    int i = (low - 1);     // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++;    // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal para executar o Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Encontra o índice do pivô, o elemento em arr[p] agora está no lugar certo
        int pi = partition(arr, low, high);

        // Classifica os elementos antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array desordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nArray ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
