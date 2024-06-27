#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sort_test.h>

int main() {
	srand(time(NULL));
	/* test_swap(); */
	test_mergeSort();
	return 0;
}
