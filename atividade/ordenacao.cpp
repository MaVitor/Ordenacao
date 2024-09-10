#include "ordenacao.hpp"

bool ordenado(int A[], unsigned int t)
{
  for (int i = 0; i < t - 1; i++)
  {
    if (A[i] > A[i + 1])
      return false;
  }
  return true;
}

void selecao(int A[], unsigned int t)
{
  int i, j, min, aux;
  for (i = 0; i < (t - 1); i++)
  {
    min = i;
    for (j = (i + 1); j < t; j++)
    {
      if (A[j] < A[min])
        min = j;
    }
    if (A[i] != A[min])
    {
      aux = A[i];
      A[i] = A[min];
      A[min] = aux;
    }
  }
}

void insercao(int A[], unsigned int t)
{
  for (unsigned int i = 1; i < t; i++)
  {
    int chave = A[i];
    int j = i - 1;

    while (j >= 0 && A[j] > chave)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = chave;
  }
}

void merge(int a[], int i1, int j1, int i2, int j2)
{
  int *temp = new int[j2 - i1 + 1];
  int i = i1, j = i2, k = 0;
  while (i <= j1 && j <= j2)
  {
    if (a[i] <= a[j])
      temp[k++] = a[i++];
    else
      temp[k++] = a[j++];
  }
  while (i <= j1)
    temp[k++] = a[i++];
  while (j <= j2)
    temp[k++] = a[j++];

  for (i = i1, k = 0; i <= j2; i++, k++)
    a[i] = temp[k];
  delete[] temp;
};

void merge_sort(int a[], int primeiro, int ultimo)
{
  if (primeiro < ultimo)
  {
    int meio = (primeiro + ultimo) / 2;
    merge_sort(a, primeiro, meio);
    merge_sort(a, meio + 1, ultimo);
    merge(a, primeiro, meio, meio + 1, ultimo);
  }
};