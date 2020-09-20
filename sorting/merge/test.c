#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "data_generator.h"
#include "merge.h"


void pretty(int *array, int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	printf("start merge sort test\n");
	
	int n = 10;

	int num_comp = 0;
	int num_swap = 0;
	
	if(argc > 1)
		n = atoi(argv[1]);

	int *array = generate(n, INVERSELY_ORDERED);

	clock_t start_time = clock();
	merge_sort(array, n);
	printf("finished. elapsed time: %f\n", (clock() - start_time)/(double)CLOCKS_PER_SEC);
	get_results(&num_comp, &num_swap);
	printf("number of comparisons: %d\nnumber of \"swaps\":%d\n", num_comp, num_swap);

	return 0;
}
