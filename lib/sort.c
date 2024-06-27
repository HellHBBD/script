#include <stdlib.h>
#include <string.h>
#include <sort.h>

void swap(void *a, void *b, size_t size) {
	void *temp = malloc(size);
	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);
	free(temp);
}

void _qsort(int *array, size_t left, size_t right) {
	if (left >= right)
		return;
	int pivot = array[(left + right) / 2];
	int l = left - 1;
	int r = right + 1;
	while (1) {
		while (array[++l] < pivot)
			;
		while (array[--r] > pivot)
			;
		if (l >= r)
			break;
		swap(&array[l], &array[r], sizeof(int));
	}
	_qsort(array, left, l - 1);
	_qsort(array, r + 1, right);
}

void quickSort(int *array, size_t length) {
	_qsort(array, 0, length);
}
