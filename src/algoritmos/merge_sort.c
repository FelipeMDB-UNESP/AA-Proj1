#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

// Função para mesclar dois subvetores ordenados em um único vetor ordenado
void merge(int *vetor, int l, int m, int r, int *trocas) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria vetores temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia os dados para os vetores temporários L[] e R[]
    for (i = 0; i < n1; i++) {
        L[i] = vetor[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = vetor[m + 1 + j];
    }

    // Mescla os vetores temporários de volta em vetor[l..r]
    i = 0; // Índice inicial do primeiro subvetores
    j = 0; // Índice inicial do segundo subvetores
    k = l; // Índice inicial do subvetores mesclado

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
            (*trocas)++; // Incrementa o contador de trocas
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }

    // Libere a memória dos vetores temporários
    free(L);
    free(R);
}

// Função principal para executar o Merge Sort
void mergeSort(int *vetor, int l, int r, int *trocas) {
    if (l < r) {
        // Encontra o ponto médio do vetor
        int m = l + (r - l) / 2;

        // Classifica a metade esquerda
        mergeSort(vetor, l, m, trocas);

        // Classifica a metade direita
        mergeSort(vetor, m + 1, r, trocas);

        // Mescla as duas metades classificadas
        merge(vetor, l, m, r, trocas);
    }
}

int main() {

    int qtdItems = 10000000;
    int *vetor = gerarVetorAleatorio(qtdItems);
    int n = qtdItems; // Tamanho do vetor
    int trocas = 0; // Inicialize o contador de trocas como 0

    // printf("Vetor desordenado:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", vetor[i]);
    // }

    
    clock_t inicio = clock();

    mergeSort(vetor, 0, n - 1, &trocas);

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // printf("\nVetor ordenado:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", vetor[i]);
    // }

    printf("\nNúmero de trocas: %d\n", trocas); // Imprime o número total de trocas
    printf("Tempo de execução do Merge Sort: %.6f segundos\n", tempo);

    // Libere a memória alocada para o vetor
    free(vetor);

    return 0;
}
