#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "data_generator.h"
#include "quick.h"


void pretty(int *array, int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	printf("start quick sort test\n");

	int n = 10;

	if(argc > 1)	//number of elements provided
		n = atoi(argv[1]);

	int num_comp = 0;
	int num_swap = 0;

	int *array = generate(n, RANDOM);

	pretty(array, n);

	clock_t start_time = clock();
	quick_sort(array, n);
	printf("finished. elasped time: %f\n", (clock() - start_time)/(double)CLOCKS_PER_SEC);
	get_results(&num_comp, &num_swap);
	printf("number of comparisons: %d\n", num_comp);
	printf("number of swaps: %d\n", num_swap);

	pretty(array, n);

	return 0;
}
