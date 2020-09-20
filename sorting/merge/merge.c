#include "merge.h"

int comp_count = 0;
int store_count = 0;

void get_results(int *num_comparisons, int *num_swaps)
{
	*num_comparisons = comp_count;
	*num_swaps = store_count;

	comp_count = 0;
	store_count = 0;
}


void merge(int *array, int start, int mid, int end)
{
	int p1, p2; //pointers to control position of each sub-array
	int size;
	bool p1_end = false, p2_end = false;

	size = (end - start + 1);

	int *temp = malloc(sizeof(int) * size);
	memset(temp, 0, size);

	p1 = start;
	p2 = mid + 1;

	if(temp != NULL){

		for(int i = 0; i < size; i++){

			if(!p1_end && !p2_end){

				comp_count++;
				if(array[p1] < array[p2]){
					temp[i] = array[p1++];
				}
				else{
					temp[i] = array[p2++];
				}

				if(p1 > mid)	p1_end = true;
				if(p2 > end)	p2_end = true;
			}
			else{
				if(!p1_end)
					temp[i] = array[p1++];
				else
					temp[i] = array[p2++];
			}
		}
	
		for(int i = 0, k = start; i < size; i++, k++){
			store_count++;
			array[k] = temp[i];
		}
	}
	free(temp);
}

void split(int *array, int start, int end)
{
	int middle;
	if(start < end){
		middle = (start + end)/2;
		split(array, start, middle);
		split(array, middle + 1, end);
		merge(array, start, middle, end);
	}
}

void merge_sort(int *array, int size)
{
	split(array, 0, size - 1);
}
