#include <stdio.h>
#include <time.h>
#include "methods.h"
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#ifdef MERGE
#define NAME "Merge"
#endif

#ifdef INSERT
#define NAME "Insert"
#endif

#ifdef BUBBLE
#define NAME "Bubble"
#endif

#ifdef MERGE
#define NAME "Merge"
#endif

#ifdef QUICK
#define NAME "Quick"
#endif

#ifdef HEAP
#define NAME "Heap"
#endif

#ifndef NAME
#define NAME "bugus"
#endif

int main(void) {
  setlocale(LC_ALL, "");
  printf("Welcome!\n");

  int count;
  scanf("%d", &count);

  int *to_sort = malloc(sizeof(int) * count);

  for (int i = 0; i < count; i++) {
    scanf("%d", &to_sort[i]);
  }

  clock_t inicio, fim;
  double tempo_cpu;

  inicio = clock();
  Sort(to_sort, count);
  fim = clock();

  free(to_sort);

  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("\n\nMetodo: %s.\nArray de tamanho %d ordenado com sucesso.\n", NAME, count);
  printf("Tempo de execucao: %f segundos.\n", tempo_cpu);
  printf("==============================");

  return 0;
}
