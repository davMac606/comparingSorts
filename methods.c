#include "methods.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
clock_t inicio, fim;
double tempo_cpu;
boolean Select(int *array, int n)
{
  if (n <= 0)
  {
    return false;
  }
  int menor = array[0];
  int temp;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      if (array[j] < menor)
      { // se o elemento atual for menor que o menor, troca os dois de posição
        menor = array[j];
        temp = array[i];
        array[i] = menor;
        array[j] = temp;
      }
      else
      {
        menor = array[i];
      }
    }
  }
  return true;
}

boolean Insert(int *array, int n)
{ // constantemente verifica se o elemento atual é menor que o anterior, se sim, troca os dois de posição
  if (n <= 0)
  {
    return false;
  }
  int j;
  for (int i = 1; i < n; i++)
  {
    int temp = array[i];
    for (j = i; (j > 0) && (temp < array[j - 1]); j--) // enquanto o elemento atual for menor que o anterior, troca os dois de posição
    {
      array[j] = array[j - 1];
    }
    array[j] = temp;
  }

  return true;
}

boolean Bubble(int *array, int n)
{
  int temp;
  if (n <= 0)
  {
    return false;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1; j++)
    { // ignorando o ultimo elemento, pois assume-se que já está ordenado
      if (array[j] > array[j + 1])
      { // se o elemento atual for maior que o proximo, troca os dois de posição
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  return true;
}

static void breakdown(int *array, int left, int pivot, int right)
{
  int i,j,k;
  int lenL = pivot - left + 1;
  int lenR = right - pivot;

  int leftPart[lenL], rightPart[lenR];
  

  for (i = 0; i < lenL; i++)
  {
    leftPart[i] = array[left + i];
  }
  for (j = 0; j < lenR; j++)
  {
    rightPart[j] = array[pivot + j + 1];
  }
  i = 0;
  j = 0;
  k = left;
  while (i < lenL && j < lenR) //enquanto i e j forem menores que o tamanho do lado esquerdo e direito, respectivamente
  {
    if (leftPart[i] <= rightPart[j]) //se o elemento do lado esquerdo for menor ou igual ao do lado direito, ele é colocado no lado esquerdo
    {
      array[k] = leftPart[i];
      i++;
    }
    else
    {
      array[k] = rightPart[j]; //se o elemento do lado direito for menor que o do lado esquerdo, ele é colocado no lado direito
      j++;
    }
    k++;
  }

  while (i < lenL)
  {
    array[k] = leftPart[i];
    i++;
    k++;
  } //enquanto i for menor que o tamanho do lado esquerdo, ele é colocado no lado esquerdo

  while (j < lenR)
  {
    array[k] = rightPart[j];
    j++;
    k++;
  } //enquanto j for menor que o tamanho do lado direito, ele é colocado no lado direito
}
static void mergeSort(int *array, int left, int right)
{
  if (left < right)
  {
    int pivot = left + (right - left) / 2;
    mergeSort(array, left, pivot);
    mergeSort(array, pivot + 1, right);
    breakdown(array, left, pivot, right);
  } //divide o array e chama a função principal do Merge Sort, onde os elementos são ordenados
}

boolean Merge(int *array, int n)
{
  if (n <= 0)
  {
    return false;
  }
  mergeSort(array, 0, n - 1); //chama a função principal do Merge Sort no array, passando o primeiro e o ultimo elemento

  return true;
}

static void troca(int *numA, int *numB)
{
  int temp = *numA;
  *numA = *numB;
  *numB = temp;
}

static int part(int *array, int left, int right)
{

  int pivot = array[left];
  int pos = right + 1;
  for (int i = right; i >= left; i--)
  {
    if (array[i] >= pivot)
    {
      pos--;
      troca(&array[i], &array[pos]);
    }
  }
  return pos;
}

static void quicksort(int *array, int left, int right)
{
  int i;
  if (right <= left)
  {
    return;
  }
  i = part(array, left, right);
  quicksort(array, left, i - 1);
  quicksort(array, i + 1, right);
}

boolean Quick(int *array, int n)
{
  if (n <= 0)
  {
    return false;
  }
  quicksort(array, 0, n - 1);
  return true;
}
// sinceramente nao sei pq a gente ta tendo coisa de arvore binaria sem ter a menor ideia doq é uma, mas nao vou reclamar sabe

void transHeap(int *array, int n, int i)
{ // i sendo a "raiz" da arvore

  int large = i; // https://bigrat.monster large?
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  // int parent = array[(i-1)/2];

  if (left < n && array[left] > array[large])
  {
    large = left;
  }

  if (right < n && array[right] > array[large])
  {
    large = right;
  }

  if (large != i)
  {
    troca(&array[i], &array[large]);
    transHeap(array, n, large);
  }
}

void formaHeap(int *array, int n)
{
  int start = (n / 2) - 1;

  for (int i = start; i >= 0; i--) {
    transHeap(array, n, i);
  }

  for (int i = n - 1; i > 0; i--)
  {
    troca(&array[0], &array[i]);

    transHeap(array, i, 0);
  }
   
}

boolean Heap(int *array, int n)
{
  if (n <= 0)
  {
    return false;
  }
  formaHeap(array, n);
  return true;
}