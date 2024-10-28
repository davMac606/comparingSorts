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

void emptyArr(int* array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = 0;
  }
}

/*void sortSel(int* sizes, int amSizes) {

  for(int i = 0; i < amSizes; i++) {
    if(!Select(iterArr(sizes[i]), sizes[i])) {
      printf("ERROR");
    }
  }
}
void sortIns(int* sizes, int amSizes) {
  for(int i = 0; i < amSizes; i++) {
    if(!Insert(iterArr(sizes[i]), sizes[i])) {
      printf("ERROR");
    }
  }
}
void sortBub(int* sizes, int amSizes) {
  for(int i = 0; i < amSizes; i++) {
    if(!Bubble(iterArr(sizes[i]), sizes[i])) {
      printf("ERROR");
    }
  }
}

void sort100(int* array, int* sizes, int amSizes) {
  if(!Select(array, sizes[0])) {
    printf("ERROR");
  }
  if (!Insert(array, sizes[0])) {
    printf("ERROR");
  }
  if (!Bubble(array, sizes[0])) {
    printf("ERROR");
  }
}
void sort1000(int* array, int* sizes, int amSizes) {
  if(!Select(array, sizes[1])) {
    printf("ERROR");
  }
  if (!Insert(array, sizes[1])) {
    printf("ERROR");
  }
  if (!Bubble(array, sizes[1])) {
    printf("ERROR");
  }
}
void sort10000(int* array, int* sizes, int amSizes) {
  if(!Select(array, sizes[2])) {
    printf("ERROR");
  }
  if (!Insert(array, sizes[2])) {
    printf("ERROR");
  }
  if (!Bubble(array, sizes[2])) {
    printf("ERROR");
  }
}
void sort50000(int* array, int* sizes, int amSizes) {
  if(!Select(array, sizes[3])) {
    printf("ERROR");
  }
  if (!Insert(array, sizes[3])) {
    printf("ERROR");
  }
  if (!Bubble(array, sizes[3])) {
    printf("ERROR");
  }
}

void sort100000(int* array, int* sizes, int amSizes) {
  if(!Select(array, sizes[4])) {
    printf("ERROR");
  }
  if (!Insert(array, sizes[4])) {
    printf("ERROR");
  }
  if (!Bubble(array, sizes[4])) {
    printf("ERROR");
  }
}*/

int main(void) {
  setlocale(LC_ALL, "");
  printf("Welcome!\n");
  void (*sorts[])(int* , int) = {Select, Insert, Bubble, Merge};
  int sizes[5] = {100,1000,10000,50000,100000};
  for (int i = 0; i < 5; i++) { 
     int *array = malloc(sizeof(int) * sizes[i]);
     iterArr(array, sizes[i]);

     for (int j = 0; j < 4; j++) {
        int *to_sort = malloc(sizeof(int) * sizes[i]);
        memcpy(to_sort, array, sizes[i] * sizeof(int));
  
        sorts[j](to_sort, sizes[i]);
        free(to_sort);
     }

      free(array);
  }
  
  return 0;
}