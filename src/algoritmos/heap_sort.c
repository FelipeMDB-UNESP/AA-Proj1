#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

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

void maxHeapify(int *vetor, int n, int i, unsigned long *trocas) {
    int maior = i;    // Inicializa o maior como a raiz
    int esquerda = 2 * i + 1; // Índice do filho esquerdo
    int direita = 2 * i + 2;  // Índice do filho direito

    // Se o filho esquerdo for maior que a raiz
    if (esquerda < n && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
    }

    // Se o filho direito for maior que a raiz
    if (direita < n && vetor[direita] > vetor[maior]) {
        maior = direita;
    }

    // Se o maior não for a raiz
    if (maior != i) {
        // Troca a raiz com o maior elemento
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;
        (*trocas)++; // Incrementa o contador de trocas

        // Chama recursivamente a função em subárvore
        maxHeapify(vetor, n, maior, trocas);
    }
}


void heapSort(int *vetor, int n, unsigned long* trocas) {

    // Constrói o heap máximo (revertendo o vetor)
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(vetor, n, i, trocas);
    }

    // Extrai elementos um por um do heap
    for (int i = n - 1; i >= 0; i--) {
        // Move a raiz atual para o final
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        (*trocas)++; // Incrementa o contador de trocas

        // Chama maxHeapify no heap reduzido
        maxHeapify(vetor, i, 0, trocas);
    }
}


int main() {
    double vetorTempo[20]; // Vetor de Testes
    double soma = 0;
    double media = 0;
    int i;
    double numero = 20;
    int qtdItems = 10000000; // Numero de Elementos
    unsigned long somaTroca = 0;
    for (i = 0; i < numero; i++)
    {
        
        int *vetor = gerarVetorAleatorio(qtdItems);
        int n = qtdItems; // Tamanho do vetor
        unsigned long trocas = 0; // Inicialize o contador de trocas como 0

        clock_t inicio = clock();

        heapSort(vetor, n, &trocas);

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
    return 0;
}