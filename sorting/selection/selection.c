#include "selection.h"

int num_comparisons = 0;
int num_swaps = 0;

void get_results(int *comparisons, int *swaps)
{
	*comparisons = num_comparisons;
	*swaps = num_swaps;

	num_comparisons = 0;
	num_swaps = 0;
}

void swap(int *array, int index1, int index2)
{
	num_swaps++;

	array[index1] = array[index1] ^ array[index2];
	array[index2] = array[index1] ^ array[index2];
	array[index1] = array[index1] ^ array[index2];
}

void selection_sort(int *array, int arrayLength)
{
	for(int i = 0; i < arrayLength - 1; i++){
		int min = i;
		bool swap_el = false; 
		for(int j = i + 1; j < arrayLength; j++){
			num_comparisons++;
			if(array[j] < array[min]){
				min = j;
				swap_el = true;
			}
		}
		if(swap_el)
			swap(array, i, min);
	}
}
