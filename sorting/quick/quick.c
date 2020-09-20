#include "quick.h"

int comp_count = 0;
int swap_count = 0;


void get_results(int *num_comparisons, int *num_swaps)
{
	*num_comparisons = comp_count;
	*num_swaps = swap_count;

	comp_count = 0;
	swap_count = 0;
}


int partition(int *array, int start, int end)
{
	int aux; //for swapping, will check for swap implementation to reduce code.
	int left, right, pivot;
	
	left = start;
	right = end;
	pivot = array[start];

	while(left < right){
		while(array[left] <= pivot){
			comp_count++;
			left++;
		}
		while(array[right] > pivot){
			comp_count++;
			right--;
		}
		if(left < right){
			comp_count++;
			swap_count++;
			aux = array[left];
			array[left] = array[right];
			array[right] = aux;
		}
	}
	array[start] = array[right];
	array[right] = pivot;
	
	return right;
}


void quick_sort_exec(int *array, int start, int end)
{
	int pivot;
	if(end > start){
		pivot = partition(array, start, end);
		quick_sort_exec(array, start, pivot - 1);
		quick_sort_exec(array, pivot + 1, end);
	}
}

void quick_sort(int *array, int size)
{
	quick_sort_exec(array, 0, size - 1);
}
