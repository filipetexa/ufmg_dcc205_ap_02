#include "../include/sort_algorithms.h"

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

void printVector(int *vet, int size)
{
    // Descricao: inicializa vet com valores aleatorios
    // Entrada: vet
    // Saida: vet
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void swap(int *xp, int *yp, sortperf_t *s)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    incmove(s, 3);
}

// shellsort
void shellSort(int *A, int n, sortperf_t *s)
{
}

// selection sort
void selectionSort(int arr[], int l, int r, sortperf_t *s)
{
    int i, j, min;
    inccalls(s, 1);
    for (i = 0; i < r - 1; i++)
    {
        min = i;
        for (j = i + 1; j < r; j++)
        {
            inccmp(s, 1);
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min], s);
    }
    return;
}

// insertion sort
void insertionSort(int v[], int l, int r, sortperf_t *s)
{
    return;
}

// median of 3 integers
int median(int a, int b, int c)
{
    if ((a <= b) && (b <= c))
        return b; // a b c
    if ((a <= c) && (c <= b))
        return c; // a c b
    if ((b <= a) && (a <= c))
        return a; // b a c
    if ((b <= c) && (c <= a))
        return c; // b c a
    if ((c <= a) && (a <= b))
        return a; // c a b
    return b;     // c b a
}

// quicksort partition using median of 3
void partition3(int *A, int l, int r, int *i, int *j, sortperf_t *s)
{
}

// standard quicksort partition
void partition(int *A, int l, int r, int *i, int *j, sortperf_t *s)
{
}

// standard quicksort
void quickSort(int *A, int l, int r, sortperf_t *s)
{
}

// quicksort with median of 3
void quickSort3(int *A, int l, int r, sortperf_t *s)
{
}

// quicksort with insertion for small partitions
void quickSortIns(int *A, int l, int r, sortperf_t *s)
{
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int *A, int l, int r, sortperf_t *s)
{
}

// recursive selection sort
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s)
{
    // find the minimum element in the unsorted subarray `[i…n-1]`
    // and swap it with `arr[i]`
    int min = l;
    inccalls(s, 1);
    for (int j = l + 1; j <= r; j++)
    {
        // if `arr[j]` is less, then it is the new minimum
        inccmp(s, 1);
        if (arr[j] < arr[min])
        {
            min = j; // update the index of minimum element
        }
    }

    // swap the minimum element in subarray `arr[i…n-1]` with `arr[i]`
    if (min != l)
        swap(&arr[min], &arr[l], s);

    if (l + 1 < r)
    {
        recursiveSelectionSort(arr, l + 1, r, s);
    }
}