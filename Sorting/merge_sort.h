#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "helper.h"

int* merge_sort (int *list, int list_size) {
	int stack_size = 2 * pow (2, list_size + 1) - 1;
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
			if (*(stack + i + 1) - *(stack + i) > 0) {
				middle_index = *(stack + i) + (*(stack + i + 1) - *(stack + i)) / 2;

				*(stack + ++stack_last_pos) = *(stack + i);
				*(stack + ++stack_last_pos) = middle_index;

				*(stack + ++stack_last_pos) = middle_index + 1;
				*(stack + ++stack_last_pos) = *(stack + i + 1);
			}
		}

		start_index = end_index + 1;
		end_index = stack_last_pos;

		divisible_flag = 0;
		for (i = start_index; i <= end_index; i += 2) {
			if (*(stack + i + 1) - *(stack + i) > 0) {
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

	// print_list ("stack", stack, stack_last_pos + 1);
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

#endif