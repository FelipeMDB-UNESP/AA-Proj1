#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função que escolhe o último elemento como pivô, coloca o elemento pivô em sua posição correta no vetor
// e coloca todos os elementos menores que o pivô à esquerda e todos os elementos maiores à direita.
int partition(int *vetor, int low, int high, int* trocas) {
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
void quickSort(int *arr, int low, int high, int* trocas) {
    if (low < high) {
        int pi = partition(arr, low, high, trocas);

        quickSort(arr, low, pi - 1, trocas);
        quickSort(arr, pi + 1, high, trocas);
    }
}

int main() {
    double vetorTempo[10]; // Vetor de Testes
    double soma = 0;
    double media = 0;
    int i;
    double numero = 10;
    int qtdItems = 1000000; // Numero de Elementos
    int somaTroca = 0;
    for (i = 0; i < numero; i++)
    {
        
        int *vetor = gerarVetorAleatorio(qtdItems);
        int n = qtdItems; // Tamanho do vetor
        int trocas = 0; // Inicialize o contador de trocas como 0

        clock_t inicio = clock();

        quickSort(vetor, 0, n - 1, &trocas);

        clock_t fim = clock();
        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        vetorTempo[i] = tempo;
        soma = soma + tempo;
        somaTroca = somaTroca + trocas;

        free(vetor);
    }

    media = soma/numero; // media
    printf("\nTestes com %d elementos\n", qtdItems);
    printf("\nMedia = %f\n", media);

    double variacoes = 0;
    int j = 0;
    for (j = 0; j < numero; j++) {
        double v = vetorTempo[j] - media;
        variacoes = variacoes + v * v;
    }
    
    double sigma = sqrt(variacoes / numero);

    printf("Desvio padrao = %f\n", sigma);

    somaTroca = somaTroca / numero;

    printf("Media Trocas = %d\n", somaTroca);
    return 0;
}
