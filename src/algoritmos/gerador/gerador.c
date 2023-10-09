#include <stdio.h>
#include <stdlib.h>
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

int main() {
    int tamanho = 10; // Tamanho do vetor desejado
    int* meuVetor = gerarVetorAleatorio(tamanho);

    if (meuVetor == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }

    // Imprimir o vetor gerado
    printf("Vetor gerado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", meuVetor[i]);
    }
    printf("\n");

    // Liberar a memória alocada para o vetor
    free(meuVetor);

    return 0;
}
