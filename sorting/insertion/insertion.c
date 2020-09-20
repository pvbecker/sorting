#include "insertion.h"

void insertion_sort(int *array, int arrayLength)
{
	int aux = 0;
	for(int i = 1; i < arrayLength; i++){
		int j = i - 1;
		aux = array[i];
		//looks for candidate position
		while(j >= 0 && aux < array[j]){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = aux;
	}
}
