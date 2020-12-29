#ifndef _SORT_H
#define _SORT_H

#include "helper.h"

/*
** Selection Sort --> Bingo Sort
** Bubble Sort
** Recursive Bubble Sort
** Insertion Sort
** Recursive Insertion Sort
** Merge Sort
** Iterative Merge Sort
** Quick Sort
** Iterative Quick Sort
** Heap Sort
** Counting Sort
** Radix Sort
** Bucket Sort
** ShellSort
** TimSort
** Comb Sort
** Pigeonhole Sort
** Cycle Sort
** Cocktail Sort
** Strand Sort



**	Comparison Sorts
	Quicksort
	Merge sort
	In-place merge sort
	Introsort
	Heapsort
	Insertion sort
	Block sort
	Quadsort
	Timsort
	Selection sort
	Cubesort
	Shellsort
	Bubble sort
	Tree sort
	Cycle sort
	Library sort
	Patience sorting
	Smoothsort
	Strand sort
	Tournament sort
	Cocktail shaker sort
	Comb sort
	Gnome sort
	UnShuffle Sort
	Franceschini's method
	Odd–even sort

**	Non-comparison sorts
	Pigeonhole sort
	Bucket sort
	Counting sort
	LSD Radix Sort
	MSD Radix Sort
	MSD Radix Sort
	Spreadsort
	Burstsort
	Flashsort
	Postman sort

** others
	Bead sort
	Simple pancake sort
	Spaghetti (Poll) sort
	Sorting network
	Bitonic sorter
	Bogosort
	Stooge sort
	Thorup's algorithm
	Randomized integer sorting

Simple sorts
	Insertion sort
	Selection sort

Efficient sorts
	Mergesort
	Heapsort
	Quicksort
	Shellsort

Bubble sort
	Bubble sort
	Fast Bubble sort
	Combsort

Distribution sort
	Counting sort
	Bucket sort
	Radix sort
*/

int* bubble_sort (int *list, int list_size) {
	int i, j;

	for (i = 0; i < list_size; i++) {
		for (j = 0; j < list_size - 1; j++) {
			if (*(list + j) > *(list + j + 1)) {
				swap_by_address ((list + j), (list + j + 1));
			}
		}
	}

	return list;
}

int* fast_bubble_sort (int *list, int list_size) {
	int a, b, c, i, j;

	for (i = 0; i < list_size; i++) {
		for (j = 0; j < list_size - 1 - i; j++) {
			a = *(list + j);
			b = *(list + j + 1);

			if (a > b) {
				c = a;
				a = b;
				b = c;
			}

			*(list + j) = a;
			*(list + j + 1) = b;
		}
	}

	return list;
}

int* selection_sort (int *list, int list_size) {
	int i, j, x;
	int min_idx;

	for (i = 0; i < list_size - 1; i++) {
		min_idx = i;

		for (j = i + 1; j < list_size; j++) {
			if (*(list + j) < *(list + min_idx)) {
				min_idx = j;
			}
		}

		if (min_idx != i) {
			x = *(list + i);
			*(list + i) = *(list + min_idx);
			*(list + min_idx) = x;
		}
	}

	return list;
}

int* insertion_sort (int *list, int list_size) {
	int i, j, x;
	
	for (i = 1; i < list_size; i++) {
		x = *(list + i);
		j = i - 1;

		while (j >= 0 && *(list + j) > x) {
			*(list + j + 1) = *(list + j);
			--j;
		}

		*(list + j + 1) = x;
	}
}

int* quick_sort (int *list, int list_size) {
	int stack_size = list_size * (int) (log2 (list_size));
	int *stack = (int*) malloc (stack_size * sizeof (int));
	int stack_last_pos = -1, start_index, end_index;
	int i, j, pivot_index;

	*(stack + ++stack_last_pos) = 0;
	*(stack + ++stack_last_pos) = list_size - 1;

	while (stack_last_pos >= 0) {
		end_index = *(stack + stack_last_pos);
		*(stack + stack_last_pos--) = 0;
		start_index = *(stack + stack_last_pos);
		*(stack + stack_last_pos--) = 0;
		// print_list (list, list_size);

		pivot_index = end_index;
		i = start_index;

		printf ("i = %d, j = %d, %d\n", i, j, stack_last_pos);
		print_list (stack, stack_size);
	
		for (j = start_index; j < end_index; j++) {
			if (*(list + j) < *(list + pivot_index)) {
				swap_by_address (list + i, list + j);
				++i;
			}
		}

		swap_by_address (list + i, list + end_index);
		pivot_index = i;

		if (start_index < pivot_index - 1) {
			*(stack + ++stack_last_pos) = start_index;
			*(stack + ++stack_last_pos) = pivot_index - 1;
		}

		if (pivot_index + 1 < end_index) {
			*(stack + ++stack_last_pos) = pivot_index + 1;
			*(stack + ++stack_last_pos) = end_index;
		}
	}

	free (stack);
	return list;
}

int* merge_sort (int *list, int list_size) {
	return list;	
}


#endif