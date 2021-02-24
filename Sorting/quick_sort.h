#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "helper.h"

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

#endif