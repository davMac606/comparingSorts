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