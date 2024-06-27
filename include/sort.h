#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

void swap(void *, void *, size_t);
void quickSort(void *, size_t, size_t, int (*)(const void *, const void *));
void mergeSort(int *, size_t, int (*)(const void *, const void *));

#endif
