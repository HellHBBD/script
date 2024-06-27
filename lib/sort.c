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

#define INDEXOF(array, i, size) ((array) + (i) * (size))
void _qsort(void *base, size_t left, size_t right, size_t size, int (*cmp)(const void *, const void *)) {
	if (left >= right)
		return;
	void *pivot = INDEXOF(base, (left + right) / 2, size);
	int l = left - 1;
	int r = right + 1;
	while (1) {
		while (1) {
			++l;
			if (cmp(INDEXOF(base, l, size), pivot) >= 0)
				break;
		}
			;
		while (1) {
			--r;
			if (cmp(INDEXOF(base, --r, size), pivot) <= 0)
				break;
		}
		if (l >= r)
			break;
		swap(INDEXOF(base, l, size), INDEXOF(base, r, size), size);
	}
	_qsort(base, left, l - 1, size, cmp);
	_qsort(base, r + 1, right, size, cmp);
}

void quickSort(void *base, size_t length, size_t size, int (*cmp)(const void *, const void *)) {
	_qsort(base, 0, length, size, cmp);
}

void merge(int *array, size_t length, int (*cmp)(const void *, const void *))
{
	size_t sublen = length / 2;
	int *merge_array = malloc(sizeof(int) * length);
	for (size_t i = 0, a = 0, b = sublen; i < length; i++)
		if (a == sublen) {
			merge_array[i] = array[b];
			b++;
		}
		else if (b == length) {
			merge_array[i] = array[a];
			a++;
		}
		/* else if (array[a] > array[b]) { */
		else if (cmp(array + a, array + b) > 0) {
			merge_array[i] = array[b];
			b++;
		}
		else {
			merge_array[i] = array[a];
			a++;
		}
	for (size_t i = 0; i < length; i++)
		array[i] = merge_array[i];
	free(merge_array);
}

void mergeSort(int *array, size_t length, int (*cmp)(const void *, const void *))
{
	if (length == 1)
		return;
	size_t sublen = length / 2;
	mergeSort(array, sublen, cmp);
	mergeSort(array + sublen, length - sublen, cmp);
	merge(array, length, cmp);
}
