#include <stdio.h>
#include <stdlib.h>
#include "selection.h"
#include <stdbool.h>
#include "data_generator.h"

void pretty(int *array, int len)
{
	for(int i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	printf("selection sort test.\n");

	int comp_count = 0;
	int swap_count = 0;

	int n;
	if(argc > 1)
		n = atoi(argv[1]);
	else
		n = 10;

	int *array = generate(n, RANDOM);
	pretty(array, n);
	selection_sort(array, n);
	pretty(array, n);
	
	get_results(&comp_count, &swap_count);
	printf("comparisons: %d\nswaps:%d\n", comp_count, swap_count);

	return 0;	
}
