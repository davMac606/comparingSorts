#include "methods.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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
  printf("==============================");
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
  printf("==============================");

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
  printf("==============================");
  return true;
}



static void breakdown(int* array, int left, int pivot, int right) {
  int lenL = pivot - left;
  int lenR = right - pivot;
  int leftPart[lenL], rightPart[lenR], i, j;
  int k = left;

  for (i = 0; i < lenL; i++) {
    leftPart[i] = array[left+1];
  }
  for (j = 0; j < lenR; j++) {
    rightPart[j] = array[pivot+j+1];
  }
  i = 0;
  j = 0;

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
static void mergeSort(int* array, int left, int right) {
  if (left < right) {
    int pivot = (left + right) / 2;
    mergeSort(array, left, pivot);
    mergeSort(array, pivot+1, right);
    breakdown(array, left, pivot, right);
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
  printf("==============================");
  return true;
}

static void troca(int* numA, int* numB) {
  int temp;
  temp = *numA;
  *numA = *numB;
  *numB = temp;

}

static int part(int* array, int left, int right) {
    int pivot = array[left];
    int pos = right + 1;
    for (int i = left; i < right; i++) {
      if (array[i] >= pivot) {
        pos--; 
        troca(&array[i], &array[left]);
      }
    }
  return pos;
}

static void quicksort(int* array, int left, int right) {
  int i;
  if (right <= left) {
    return;
  }
  i = part(array, left, right);
  quicksort(array, left, i-1);
  quicksort(array, i+1, right);
}

boolean Quick(int* array, int n) {
  inicio = clock();
  if (n <= 0) {
    return false;
  }
  quicksort(array, 0, n-1);
  fim = clock();
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("\n\nMetodo: Quick.\nArray de tamanho %d ordenado com sucesso.\n", n);
  printf("Tempo de execucao: %f segundos.\n", tempo_cpu);
  printf("==============================");
  return true;
}
//sinceramente nao sei pq a gente ta tendo coisa de arvore binaria sem ter a menor ideia doq é uma, mas nao vou reclamar sabe

static void transHeap(int* array, int n, int i) {//i sendo a "raiz" da arvore

  int large = i; //https://bigrat.monster large?
  int left = 2*i + 1;
  int right = 2*i + 2;
  //int parent = array[(i-1)/2];

  if (array[left] > array[large]) {
    large = left;
  }

  if (array[right] > array[large]) {
    large = right;
  }

  if (large != i) {
    troca(&array[i], &array[large]);
    transHeap(array, n, large);
  }

  
}

void formaHeap(int* array, int n) {
  int start = (n/2) - 1; 

  for (int i = start; i >= 0; i--) 
    transHeap(array, n, i);
}

boolean Heap(int* array, int n) {
  inicio = clock();
  if (n <= 0) {
    return false;
  }
  formaHeap(array, n);
  fim = clock();
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("\n\nMetodo: Heap.\nArray de tamanho %d ordenado com sucesso.\n", n);
  printf("Tempo de execucao: %f segundos.\n", tempo_cpu);
  printf("==============================");
  return true;
}