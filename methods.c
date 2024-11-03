#include "methods.h"
#include <stdlib.h>

#ifdef SELECT
#define FUNC Select

boolean Select(int *array, int n) {
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

  return true;
}
#endif

#ifdef INSERT
#define FUNC Insert

boolean Insert(int *array, int n) {
  if (n <= 0) {
    return false;
  }
  int j;
  for (int i = 1; i < n; i++) {
    int temp = array[i];
    for (j = i; (j > 0) && (temp < array[j - 1]); j--) {
        array[j] = array[j - 1];
    }
    array[j] = temp;
  }

  return true;
}
#endif

#ifdef BUBBLE
#define FUNC Bubble

boolean Bubble(int *array, int n) {
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

  return true;
}
#endif

#ifdef MERGE
#define FUNC Merge

static void breakdown(int* array, int left, int pivot, int right) {
  int lenL = pivot - left;
  int lenR = right - pivot;
  int *leftPart = malloc(sizeof(int) * lenL);
  int *rightPart = malloc(sizeof(int) * lenR);
  int i, j;
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
  if (n <= 0) {
    return false;
  }
  mergeSort(array, 0, n-1);

  return true;
}
#endif


#if defined(QUICK) || defined(HEAP)
static void troca(int* numA, int* numB) {
  int temp;
  temp = *numA;
  *numA = *numB;
  *numB = temp;
}
#endif

#ifdef QUICK
#define FUNC Quick

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
  if (n <= 0) {
    return false;
  }
  quicksort(array, 0, n-1);

  return true;
}
//sinceramente nao sei pq a gente ta tendo coisa de arvore binaria sem ter a menor ideia doq é uma, mas nao vou reclamar sabe

#endif

#ifdef HEAP
#define FUNC Heap

static void transHeap(int* array, int n, int i) {//i sendo a "raiz" da arvore
  int large = i; //https://bigrat.monster large?
  int left = 2*i + 1;
  int right = 2*i + 2;
  //int parent = array[(i-1)/2];

  if (left < n && array[left] > array[large]) {
    large = left;
  }

  if (right < n && array[right] > array[large]) {
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
  if (n <= 0) {
    return false;
  }
  formaHeap(array, n);

  return true;
}
#endif

#ifndef FUNC
inline boolean Sort(int *array, int n) {
  return false;
}
#else
inline boolean Sort(int *array, int n) {
  return FUNC(array, n);
}
#endif
