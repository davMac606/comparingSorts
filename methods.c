#include "methods.h"
#include <stdio.h>
#include <time.h>
clock_t inicio, fim;
double tempo_cpu;

boolean Select(int *array, int n) {
  inicio = clock();
 
  if (n <= 0) {
    return false;
  }
  int menor = array[0];
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (array[j] < menor) {
        menor = array[j];
        temp = array[i];
        array[i] = menor;
        array[j] = temp;
      } else {
        menor = array[i];
      }
    }
  }
  fim = clock();
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("\n\nMetodo: Select.\nArray de tamanho %d ordenado com sucesso.\n", n);
  printf("Tempo de execucao: %f segundos.\n", tempo_cpu);
  return true;

}

boolean Insert(int *array, int n) {
  inicio = clock();
  if (n <= 0) {
    return false;
  }
  int j;
  for (int i = 1; i < n; i++)
    {
        int temp = array[i];
        for (j = i; (j > 0) && (temp < array[j - 1]); j--)
        {
            array[j] = array[j - 1];
        }
        array[j] = temp;
    }

  fim = clock();
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("\n\nMetodo: Insert.\nArray de tamanho %d ordenado com sucesso.\n", n);
  printf("Tempo de execucao: %f segundos.\n", tempo_cpu);

  return true;
}

boolean Bubble(int *array, int n) {
  inicio = clock();
  int temp;
  if (n <= 0) {
    return false;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-1; j++) { 
        if (array[j] > array[j+1]) {
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }

  }
  fim = clock();
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("\n\nMetodo: Bubble.\nArray de tamanho %d ordenado com sucesso.\n", n);
  printf("Tempo de execucao: %f segundos.\n", tempo_cpu);
  return true;
}

void mergeSort(int* array, int left, int right) {
  if (left < right) {
    int pivot = (left + right) / 2;
    mergeSort(array, left, pivot);
    mergeSort(array, pivot+1, right);
    breakdown(array, left, pivot, right);
  }
}

void breakdown(int* array, int left, int pivot, int right) {
  int lenL = pivot - left;
  int lenR = right - pivot;
  int leftPart[lenL], rightPart[lenR], i, j, k;

  for (i = 0; i < lenL; i++) {
    leftPart[i] = array[left+1];
  }
  for (j = 0; j < lenR; j++) {
    rightPart[j] = array[pivot+j+1];
  }
  i,j = 0;
  k = left;

  while (i < lenL && j < lenR) {
    if (leftPart[i] <= rightPart[j]) {
      array[k] = leftPart[i];
      i++;
    } else {
      array[k] = rightPart[j];
      j++;
    }
    k++;
  }

  while (i < lenL) {
        array[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < lenR) {
        array[k] = rightPart[j];
        j++;
        k++;
    }
}


boolean Merge(int* array, int n) {
  inicio = clock();
  if (n <= 0) {
    return false;
  }
  mergeSort(array, 0, n-1);
  fim = clock();
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("\n\nMetodo: Merge.\nArray de tamanho %d ordenado com sucesso.\n", n);
  printf("Tempo de execucao: %f segundos.\n", tempo_cpu);

  return true;
}