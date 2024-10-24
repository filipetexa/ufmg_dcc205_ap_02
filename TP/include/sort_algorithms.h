#ifndef REC_SELECTOR_H
#define REC_SELECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "instrumentation.h"

void initVector(int *vet, int size);
void printVector(int *vet, int size);
void swap(int *xp, int *yp, sortperf_t *s);
void shellSort(int *A, int n, sortperf_t *s);
void selectionSort(int arr[], int l, int r, sortperf_t *s);
void insertionSort(int v[], int l, int r, sortperf_t *s);
void partition3(int *A, int l, int r, int *i, int *j, sortperf_t *s);
void partition(int *A, int l, int r, int *i, int *j, sortperf_t *s);
void quickSort(int *A, int l, int r, sortperf_t *s);
void quickSort3(int *A, int l, int r, sortperf_t *s);
void quickSortIns(int *A, int l, int r, sortperf_t *s);
void quickSort3Ins(int *A, int l, int r, sortperf_t *s);
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s);

#endif // REC_SELECTOR_H