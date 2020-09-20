#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubble.h"
#include "../../data_generator/data_generator.h"


void pretty(int *array, int length)
{
	for(int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	printf("start bubble sorting test\n");

	int num_comp = 0;
	int num_swap = 0;

	int *array;
	int arraySize;
	if(argc > 1)
		arraySize = atoi(argv[1]);
	else
		arraySize = 10;

	array = generate(arraySize, RANDOM);
	printf("random array contents: ");

	printf("start sorting...\n");
	clock_t start_time = clock();
	bubble_sort(array, arraySize);
	get_results(&num_comp, &num_swap);
	printf("finished. elapsed time: %f\n", (clock() - start_time)/(double)CLOCKS_PER_SEC);
	printf("number of comparisons:	%d\n", num_comp);
	printf("number of swaps: 	%d\n", num_swap);

	return 0;
}
