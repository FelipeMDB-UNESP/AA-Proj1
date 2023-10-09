#ifndef algoritmos_ordenacao
#define algoritmos_ordenacao

// Função para ordenar um array usando o algoritmo Insertion Sort
void insertionSort(int vetor[], int n);

// Função para ordenar um array usando o algoritmo Selection Sort
void selectionSort(int vetor[], int n);

// Função para ordenar um array usando o algoritmo Merge Sort
void mergeSort(int vetor[], int l, int r);

// Função para ordenar um array usando o algoritmo Quick Sort
void quickSort(int vetor[], int low, int high);

#endif /* algoritmos_ordenacao */

#ifndef gerador
#define gerador

int* gerarVetorAleatorio(int tamanho);

#endif