#include "../include/sort_algorithms.h"
#define CUTOFF 20

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
void insertionSort(int arr[], int l, int r, sortperf_t *s)
{
    int i, j, temp;
    inccalls(s, 1);

    for (i = 0; i < r; i++)
    {
        temp = arr[i];
        incmove(s, 1);
        j = i;

        while (j > 0 && temp < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            incmove(s, 1);
            j--;
            inccmp(s, 1);
        }
        inccmp(s, 1);
        arr[j] = temp;
        incmove(s, 1);
    }

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
void partition3(int *arr, int l, int r, int *i, int *j, sortperf_t *s)
{
    int pivot;
    *i = l;
    *j = r;
    // Implementando a mediana de três para escolher o pivô
    int mid = l + (r - l) / 2; // Encontra o índice médio
    if (arr[l] > arr[mid])
        swap(&arr[l], &arr[mid], s); // Troca se necessário
    if (arr[l] > arr[r])
        swap(&arr[l], &arr[r], s); // Troca se necessário
    if (arr[mid] > arr[r])
        swap(&arr[mid], &arr[r], s); // Troca se necessário

    pivot = arr[mid];             // A mediana agora está no meio
    swap(&arr[mid], &arr[*j], s); // Move a mediana para o final para usá-la como pivô

    do
    {
        inccmp(s, 1);
        while (arr[*i] < pivot)
        {
            inccmp(s, 1);
            (*i)++;
        }
        inccmp(s, 1);
        while (arr[*j] > pivot)
        {
            inccmp(s, 1);
            (*j)--;
        }

        if (*i <= *j)
        {
            swap(&arr[*i], &arr[*j], s); // Troca os elementos
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

// standard quicksort partition
void partition(int *arr, int l, int r, int *i, int *j, sortperf_t *s)
{
    // printVector(arr, r - l);
    int pivot;
    *i = l;
    *j = r;
    pivot = arr[(*i + *j) / 2];

    do
    {
        inccmp(s, 1);
        while (pivot > arr[*i])
        {
            inccmp(s, 1);
            (*i)++;
        }
        inccmp(s, 1);
        while (pivot < arr[*j])
        {
            inccmp(s, 1);
            (*j)--;
        }

        if (*i <= *j)
        {
            swap(&arr[*i], &arr[*j], s);
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

// standard quicksort
void quickSort(int *arr, int l, int r, sortperf_t *s)
{
    inccalls(s, 1);
    int i, j;
    partition(arr, l, r, &i, &j, s);
    if (l < j)
        quickSort(arr, l, j, s);
    if (i < r)
        quickSort(arr, i, r, s);
}

// quicksort with median of 3
void quickSort3(int *arr, int l, int r, sortperf_t *s)
{
    int i, j;
    partition3(arr, l, r, &i, &j, s);
    if (l < j)
        quickSort(arr, l, j, s);
    if (i < r)
        quickSort(arr, i, r, s);
}

// quicksort with insertion for small partitions
void quickSortIns(int *arr, int l, int r, sortperf_t *s)
{
    inccalls(s, 1);
    if (r - l < CUTOFF)
    {
        insertionSort(arr, l, r, s);
        return;
    }

    int i, j;
    partition(arr, l, r, &i, &j, s);
    if (l < j)
        quickSortIns(arr, l, j, s);
    if (i < r)
        quickSortIns(arr, i, r, s);
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int *arr, int l, int r, sortperf_t *s)
{

    inccalls(s, 1);
    if (r - l < CUTOFF)
    {
        insertionSort(arr, l, r, s);
        return;
    }

    int i, j;
    partition3(arr, l, r, &i, &j, s);
    if (l < j)
        quickSort3Ins(arr, l, j, s);
    if (i < r)
        quickSort3Ins(arr, i, r, s);
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