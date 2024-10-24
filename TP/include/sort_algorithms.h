#ifndef REC_SELECTOR_H
#define REC_SELECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "instrumentation.h"

void initVector(int *vet, int size);
void printVector(int *vet, int size);
void swap(int *xp, int *yp, sortperf_t *s);
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s);

#endif // REC_SELECTOR_H