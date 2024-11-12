#include <stdio.h>
#include <time.h>
// #include "methods.h" should be the right one, but VSCode does not work with it. keep in mind.
#include "methods.c"
#include <locale.h>
#include <string.h>
#include <stdlib.h>

void iterArr(int *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = rand();
  }
}

int *arrayTeste(int size)
{
  srand(time(NULL));
  int *array = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++)
  {
    array[i] = rand();
  }
  return array;
}
int main(void)
{
  setlocale(LC_ALL, "");
  printf("Welcome!\n");
  clock_t inicio, fim;
  double tempo_cpu;
  FILE *file;
  file = fopen("D:\\PUCC\\ERD\\feedbacks\\results.txt", "a");
  boolean (*sorts[])(int *, int) = {SELECT, INSERT, BUBBLE, MERGE, QUICK, HEAP};

  char *names[] = {"Select", "Insert", "Bubble", "Merge", "Quick", "Heap"};

  int sizes[] = {100, 1000, 10000, 50000, 100000};
  for (int i = 0; i < 5; i++)
  {
    int *array = malloc(sizeof(int) * sizes[i]);
    iterArr(array, sizes[i]);
    for (int j = 0; j < 6; j++)
    {
      int *to_sort = malloc(sizeof(int) * sizes[i]);
      memcpy(to_sort, array, sizes[i] * sizeof(int));

      inicio = clock();
      sorts[j](to_sort, sizes[i]);
      fim = clock();

      free(to_sort);

      tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

      fprintf(file, "\n%s;%d;%f", names[j], sizes[i], tempo_cpu);
      printf("\n\nMetodo: %s.\nArray de tamanho %d ordenado com sucesso.\n", names[j], sizes[i]);
      printf("Tempo de execucao: %f segundos.\n", tempo_cpu);
      printf("==============================");
    }
  }
  return 0;
}
