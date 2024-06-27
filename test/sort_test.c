#include <stdio.h>
#include <stdlib.h>

#include <sort.h>
#include <sort_test.h>

void test_swap() {
	int a = 3, b = -10;
	printf("%d %d\n", a, b);
	swap(&a, &b, sizeof(int));
	printf("%d %d\n", a, b);
	double c = 3.1415, d = 2.71828;
	printf("%lf %lf\n", c, d);
	swap(&c, &d, sizeof(double));
	printf("%lf %lf\n", c, d);
	void *e = &a, *f = &c;
	printf("%p %p\n", e, f);
	swap(&e, &f, sizeof(void *));
	printf("%p %p\n", e, f);
}

int increase(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

/* int decrease(const void *a, const void *b) { */
	/* return *(int *)b - *(int *)a; */
/* } */

#define SIZE 10
/* void test_quickSort() { */
/* 	int array[SIZE]; */
/* 	for (int i = 0;i < SIZE;i++) { */
/* 		array[i] = rand() % (2 * SIZE); */
/* 		printf("%d ", array[i]); */
/* 	} */
/* 	puts(""); */
/*  */
/* 	quickSort(array, SIZE, sizeof(int), increase); */
/*  */
/* 	for (int i = 0;i < SIZE;i++) { */
/* 		printf("%d ", array[i]); */
/* 	} */
/* 	puts(""); */
/*  */
/* 	quickSort(array, SIZE, sizeof(int), decrease); */
/*  */
/* 	for (int i = 0;i < SIZE;i++) { */
/* 		printf("%d ", array[i]); */
/* 	} */
/* 	puts(""); */
/* } */

void test_mergeSort() {
	int array[SIZE];
	for (int i = 0;i < SIZE;i++) {
		array[i] = rand() % (2 * SIZE);
		printf("%d ", array[i]);
	}
	puts("");

	mergeSort(array, SIZE, increase);

	for (int i = 0;i < SIZE;i++) {
		printf("%d ", array[i]);
	}
	puts("");

	/* mergeSort(array, SIZE); */
    /*  */
	/* for (int i = 0;i < SIZE;i++) { */
	/* 	printf("%d ", array[i]); */
	/* } */
	/* puts(""); */
}
