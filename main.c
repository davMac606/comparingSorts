#include <stdio.h>
#include <time.h>
#include "methods.c"
#include <locale.h>
#include <string.h>
#include <stdlib.h>

void iterArr(int* array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = rand();
  }
}

int* arrayTeste(int size) {
  srand(time(NULL));
  int* array = (int*)malloc(size*sizeof(int));
  for (int i = 0; i < size; i++) {
    array[i] = rand();
  }
  return array;
}
int main(void) {
  setlocale(LC_ALL, "");
  printf("Welcome!\n");
  void (*sorts[])(int* , int) = {Select, Insert, Bubble, Merge, Quick, Heap};
  int sizes[5] = {100,1000,10000,50000,100000};
  for (int i = 0; i < 5; i++) { 
     int *array = malloc(sizeof(int) * sizes[i]);
     iterArr(array, sizes[i]);
     for (int j = 0; j < 6; j++) {
        int* to_sort = malloc(sizeof(int) * sizes[i]);
        memcpy(to_sort, array, sizes[i] * sizeof(int));
  
        sorts[j](to_sort, sizes[i]);
        free(to_sort);
     }

  }
  return 0;
}