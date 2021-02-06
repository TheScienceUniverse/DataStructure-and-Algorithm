#ifndef _SORT_H
#define _SORT_H

#include "helper.h"

/*

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

		// printf ("i = %d, j = %d, %d\n", i, j, stack_last_pos);
		// print_list (stack, stack_size);
	
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
	int stack_size = 2 * list_size * (int) (log2 (list_size));
	int *stack = (int*) calloc (stack_size, sizeof (int));
	int stack_last_pos = -1;
	int divisible_flag = 0, tree_level = 0;
	int i, start_index, end_index, middle_index; // indexes: iterator, start, end, middle

	// indexing and making sorting tree
	if (list_size <= 1) {
		divisible_flag = -1;		// is divisible? hell no!
		return list;
	} else if (list_size == 2) {
		divisible_flag = 0;			// is divisible? what's the point!

		if (*(list + 0) > *(list + 1)) {
			swap_by_address (list + 0, list + 1);
		}

		return list;
	} else {
		divisible_flag = 1;		// is divisible? hell yes!
		
		start_index = 0;
		end_index = 1;

		*(stack + ++stack_last_pos) = 0;
		*(stack + ++stack_last_pos) = list_size - 1;
	}

	while (divisible_flag == 1) {	// rejected if non divisible
		tree_level += 1;

		for (i = start_index; i < end_index; i += 2) {
			if (*(stack + i + 1) - *(stack + i) > 1) {
				middle_index = *(stack + i) + (*(stack + i + 1) - *(stack + i)) / 2;

				*(stack + ++stack_last_pos) = *(stack + i);
				*(stack + ++stack_last_pos) = middle_index;

				*(stack + ++stack_last_pos) = middle_index + 1;
				*(stack + ++stack_last_pos) = *(stack + i + 1);
			} else {
				*(stack + ++stack_last_pos) = *(stack + i);
				*(stack + ++stack_last_pos) = *(stack + i + 1);
			}
		}

		start_index = end_index + 1;
		end_index = stack_last_pos;

		divisible_flag = 0;
		for (i = start_index; i <= end_index; i += 2) {
			if (*(stack + i + 1) - *(stack + i) > 1) {
				divisible_flag = 1;
				break;
			}
		}
	}
	// print_list ("stack", stack, stack_last_pos + 1);

	// merging
	int *temp = (int*) calloc (list_size, sizeof (int));
	int s1, s2, e1, e2;		// indexes: start and end for temp list 1 and 2
	int a, b, c;

	// sorting leave nodes (undivisible range)
	// but not decreasing stack_last_pos
	c = stack_last_pos;

	do {
		e2 = *(stack + c--);
		s2 = *(stack + c--);

		if (*(list + s2) > *(list + e2)) {
			swap_by_address (list + s2, list + e2);
		}
	} while (s2 != 0);

	// print_list ("stack", stack, stack_last_pos + 1);
	//printf ("1st level sorted");
	//print_list ("array", list, list_size);

	--tree_level;

	while (stack_last_pos > 1) {
		e2 = *(stack + stack_last_pos--);
		s2 = *(stack + stack_last_pos--);

		e1 = *(stack + stack_last_pos--);
		s1 = *(stack + stack_last_pos--);

		a = s1, b = s2, c = 0;
		// printf ("%d - %d, %d - %d\n", s1, e1, s2, e2);
		// print_list ("list", list, list_size);

		while (a <= e1 && b <= e2) {
			if (*(list + a) < *(list + b)) {
				*(temp + c++) = *(list + a++);
			} else {
				*(temp + c++) = *(list + b++);
			}
		}

		while (a <= e1) {
			*(temp + c++) = *(list + a++);
		}

		while (b <= e2) {
			*(temp + c++) = *(list + b++);
		}

		for (i = 0; i < c; i++) {
			*(list + s1 + i) = *(temp + i);
		}
	}

	return list;
}

int* counting_sort (int *list, int list_size) {
	int i;
	int min = *(list + 0), max = *(list + 0);

	for (i = 1; i < list_size; i++) {
		if (*(list + i) > max)
			max = *(list + i);
		if (*(list + i) < min)
			min = *(list + i);
	}

	printf ("max = %d, min = %d\n", max, min);

	if (min < 0) {
		min = -min;

		for (i = 0; i < list_size; i++) {
			
		}
	}
}

#endif