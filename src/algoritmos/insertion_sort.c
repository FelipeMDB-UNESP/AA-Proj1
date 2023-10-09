#include <stdio.h>
#include <time.h>

void insertionSort(int vetor[], int n, int *trocas) {
    clock_t inicio = clock();
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
            (*trocas)++;
        }
        vetor[j + 1] = chave;
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Insertion Sort: %.6f segundos\n", tempo);
}

int main() {
    int vetor[] = {12, 11, 13, 5, 6};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int trocas = 0;

    printf("Vetor desordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    insertionSort(vetor, n, &trocas);

    printf("\nVetor ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nNúmero de trocas: %d\n", trocas);
    return 0;
}
