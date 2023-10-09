#include <stdio.h>

void insertionSort(int vetor[], int n) {
    int i, chave, j, trocas = 0; // Inicialize o contador de trocas como 0
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;

        // Move os elementos da parte ordenada da matriz
        // que são maiores que a chave, para uma posição à frente de sua posição atual.
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
            trocas++; // Incrementa o contador de trocas
        }
        vetor[j + 1] = chave;
    }

    printf("Número de trocas: %d\n", trocas); // Imprime o número total de trocas
}

int main() {
    int vetor[] = {12, 11, 13, 5, 6};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    insertionSort(vetor, n);

    printf("Vetor ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
