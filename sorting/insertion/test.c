#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../../data_generator/data_generator.h"
#include "insertion.h"

void pretty(int *array, int arraySize)
{
	for(int i = 0; i < arraySize; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	printf("insertion sort test\n");

	int arraySize;
	
	if(argc > 1)
		arraySize = atoi(argv[1]);
	else
		arraySize = 10;

	int *array = generate(arraySize, RANDOM);
//	pretty(array, arraySize);

	clock_t start_time = clock();
	printf("start sorting...\n");
	insertion_sort(array, arraySize);
	printf("elapsed time: %f\n", (clock() - start_time)/(double)CLOCKS_PER_SEC);
//	pretty(array, arraySize);

	return 0;
}
