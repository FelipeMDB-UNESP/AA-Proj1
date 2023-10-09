#include <stdio.h>

void selectionSort(int vetor[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        // Encontra o índice do menor elemento na parte não ordenada da matriz
        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        temp = vetor[i];
        vetor[i] = vetor[minIndex];
        vetor[minIndex] = temp;
    }
}

int main() {
    int vetor[] = {64, 25, 12, 22, 11};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    selectionSort(vetor, n);

    printf("Vetor ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
