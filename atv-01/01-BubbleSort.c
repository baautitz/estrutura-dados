/**
 * Faça um bubble sort e imprima o array após cada iteração. Teste com o melhor
 * e o pior caso.
 */
#include <stdio.h>

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int tmp, trocou = 0;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                trocou = 1;
            }

            printArray(arr, size);

            if (!trocou)
                break;
        }
    }
}

void main() {
    int melhorCaso[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int piorCaso[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    printf("Testando com o melhor caso...\n");
    bubleSort(melhorCaso, 10);

    printf("\nTestando com o pior caso...\n");
    bubleSort(piorCaso, 10);
}
