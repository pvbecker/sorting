#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#ifdef DEBUG
#include <stdio.h>
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...) (void)0
#endif


void get_results(int *num_comparisons, int *num_swaps);
void merge_sort(int *array, int size);
