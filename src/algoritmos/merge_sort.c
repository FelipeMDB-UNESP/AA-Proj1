#include <stdio.h>
#include <time.h>

// Função para mesclar dois subarrays ordenados em um único array ordenado
void merge(int arr[], int l, int m, int r, int *trocas) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Mescla os arrays temporários de volta em arr[l..r]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = l; // Índice inicial do subarray mesclado

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            (*trocas)++; // Incrementa o contador de trocas
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal para executar o Merge Sort
void mergeSort(int arr[], int l, int r, int *trocas) {
    clock_t inicio = clock();
    if (l < r) {
        // Encontra o ponto médio do array
        int m = l + (r - l) / 2;

        // Classifica a metade esquerda
        mergeSort(arr, l, m, trocas);

        // Classifica a metade direita
        mergeSort(arr, m + 1, r, trocas);

        // Mescla as duas metades classificadas
        merge(arr, l, m, r, trocas);
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Merge Sort: %.6f segundos\n", tempo);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int trocas = 0; // Inicialize o contador de trocas como 0

    printf("Array desordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, n - 1, &trocas);

    printf("\nArray ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNúmero de trocas: %d\n", trocas); // Imprime o número total de trocas
    return 0;
}
