#include <stdio.h>
#include <time.h>

// Função para gerar um vetor com valores aleatórios
int* gerarVetorAleatorio(int tamanho) {
    int* vetor = (int*)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        // Tratar erro de alocação de memória
        return NULL;
    }

    // Inicializar a semente para números aleatórios
    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand(); // Preencher o vetor com números aleatórios
    }

    return vetor;
}

void selectionSort(int *vetor, int n, int *trocas) {
    clock_t inicio = clock();
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }

        temp = vetor[i];
        vetor[i] = vetor[minIndex];
        vetor[minIndex] = temp;
        (*trocas)++;
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Selection Sort: %.6f segundos\n", tempo);
}


int main() {
    int vetor[] = {64, 25, 12, 22, 11};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int trocas = 0;

    printf("Vetor desordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    selectionSort(vetor, n, &trocas);

    printf("\nVetor ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nNúmero de trocas: %d\n", trocas);
    return 0;
}
