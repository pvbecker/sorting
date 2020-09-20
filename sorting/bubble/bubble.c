#include "bubble.h"

int num_comp = 0;
int num_swap = 0;

void get_results(int *comp_count, int *swap_count)
{
	*comp_count = num_comp;
	*swap_count = num_swap;

	num_comp = 0;
	num_swap = 0;
}

void swap(int *array, int index1, int index2)
{
	num_swap++;
	array[index1] = array[index1] ^ array[index2];
	array[index2] = array[index1] ^ array[index2];
	array[index1] = array[index1] ^ array[index2];
}

void bubble_sort(int *array, int arrayLength)
{
	for(int i = 0; i < arrayLength - 1; i++){
		for(int j = i + 1; j < arrayLength; j++){
			num_comp++;
			if(array[i] > array[j])
				swap(array, i, j);
		}
	}
}
