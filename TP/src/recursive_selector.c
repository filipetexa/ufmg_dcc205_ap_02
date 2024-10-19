#include "../include/recursive_selector.h"

void initVector(int *vet, int size)
{
    // Descricao: inicializa vet com valores aleatorios
    // Entrada: vet
    // Saida: vet
    int i;
    for (i = 0; i < size; i++)
    {
        vet[i] = (int)(drand48() * size);
    }
}
void swap(int *xp, int *yp, sortperf_t *s)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    incmove(s, 3);
}

void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s)
{
    int min = l;
    inccalls(s, 1);
    for (int j = l + 1; j <= r; j++)
    {
        inccmp(s, 1);
        if (arr[j] < arr[min])
        {
            min = j;
        }
    }
    if (min != l)
        swap(&arr[min], &arr[l], s);
    if (l + 1 < r)
    {
        recursiveSelectionSort(arr, l + 1, r, s);
    }
}
