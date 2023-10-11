#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void insertionSort(int *vetor, int n, unsigned long *trocas) {
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
}

int main() {
    double vetorTempo[1]; // Vetor de Testes
    double soma = 0;
    double media = 0;
    int i;
    double numero = 1;
    int qtdItems = 100; // Numero de Elementos
    unsigned long somaTroca = 0;
    for (i = 0; i < numero; i++)
    {
        
        int *vetor = gerarVetorAleatorio(qtdItems);
        int n = qtdItems; // Tamanho do vetor
        unsigned long trocas = 0; // Inicialize o contador de trocas como 0

        clock_t inicio = clock();

        insertionSort(vetor, n, &trocas);

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

    printf("Media Trocas = %ld\n", somaTroca);
    printf("max rand = %ld", RAND_MAX);
    return 0;
}
