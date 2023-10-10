#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define QUANT 10000000

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

    

    // printf("Vetor desordenado:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", vetor[i]);
    // }

    
    

    // printf("\nVetor ordenado:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", vetor[i]);
    // }

   // printf("\nNúmero de trocas: %d\n", trocas); // Imprime o número total de trocas
   // printf("Tempo de execução do Merge Sort: %.6f segundos\n", tempo);

    double vetorTempo[10]; // Vetor de Testes
    double soma = 0;
    double media = 0;
    int i;
    double numero = 10;
    int qtdItems = QUANT; // Numero de Elementos
    for (i = 0; i < numero; i++)
    {
        
        int *vetor = gerarVetorAleatorio(qtdItems);
        int n = qtdItems; // Tamanho do vetor
        int trocas = 0; // Inicialize o contador de trocas como 0

        clock_t inicio = clock();

        mergeSort(vetor, 0, n - 1, &trocas);

        clock_t fim = clock();
        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        vetorTempo[i] = tempo;
        soma = soma + tempo;

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
    










    // printf("⠀⠀⠀⠀⠀⣀⣴⣶⣶⣶⣶⣶⣶⣶⣦⣄⣀⠀⠀⠀⠀⠀\n");
    // printf("⠀⠀⣀⣴⣾⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀⠀\n");
    // printf("⠀⠀⣿⣿⣿⣿⣿⣿⠉⠀⠀⠀⠀⠀⠉⠉⠉⠙⢷⡄⠀⠀\n");
    // printf("⠀⣼⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡄⠀\n");
    // printf("⠀⣿⣿⣿⣿⣿⡿⠛⠁⠀⣠⣾⣿⣶⣤⣤⣄⠀⠀⠀⡇⠀\n");
    // printf("⠀⣿⣿⣿⣿⣿⠁⠀⠀⠚⠉⣴⣶⣦⡌⠙⠛⠀⣶⣶⣽⡄\n");
    // printf("⣴⡿⠉⠻⣿⣿⠀⠀⠀⠀⠀⠀⠀⠉⠙⠀⠀⢆⣤⣭⡙⡇\n");
    // printf("⣿⠀⠉⠇⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠑⡄⠀⡇\n");
    // printf("⠻⣍⠑⠇⣿⣿⣿⣷⣦⣄⡀⣀⣠⣤⣼⣦⣀⣠⣤⡇⠀⡇\n");
    // printf("⠀⣿⡟⢲⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣴⠇\n");
    // printf("⠀⣿⡇⣼⣿⣿⣿⣿⣿⣿⣿⣷⣆⣀⠀⠉⠉⢿⣿⡿\n");
    // printf("⠀⣿⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀\n");
    // printf("⠀⣿⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀\n");
    // printf("⣼⡿⠀⠀⠀⠀⠀⠉⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀\n");
    // printf("⣿⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀\n");
    // Libere a memória alocada para o vetor
    

    return 0;
}
