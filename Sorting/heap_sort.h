#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "helper.h"

int* heap_sort (int*, int);
void fill_heap (int*, int);				// O (n * log{2}(n))
int* heapify (int*, int);				// O (n)
void empty_heap (int*, int);
void insert_into_heap (int);		// O (log{2}(n))
int delete_from_heap (void);		// O (log{2}(n))

int *heap = NULL;		// min_heap [dynamic array list] [not using linked list format]
int heap_last_index = -1;

int* heap_sort (int *list, int list_size) {
	fill_heap (list, list_size);
	// print_list ("heap", heap, heap_last_index + 1);
	empty_heap (list, list_size);

	free (heap);

	return list;
}

void fill_heap (int *list, int list_size) {
	int i;
	heap = (int*) calloc (list_size, sizeof (int));

	for (i = 0; i < list_size; i++) {
		insert_into_heap (*(list + i));
	}
}

void empty_heap (int *list, int list_size) {
	for (int i = 0; i < list_size; i++) {
		*(list + i) = delete_from_heap();
	}
	printf ("\n");
}

void insert_into_heap (int element) {
	*(heap + ++heap_last_index) = element;

	int current_index = heap_last_index;
	int parent_index;

	while (current_index != 0) {
		parent_index = (current_index - 1) / 2;

		if (*(heap + current_index) < *(heap + parent_index)) {
			swap_by_address (heap + current_index, heap + parent_index);
		}

		current_index = parent_index;
	}
}

int delete_from_heap (void) {
	int root_elem = *(heap + 0);

	*(heap) = *(heap + heap_last_index--);

	int current_index = 0;
	int child_index_1, child_index_2;

	while (current_index < heap_last_index) {
		child_index_1 = 2 * current_index + 1;
		child_index_2 = 2 * current_index + 2;

		if (child_index_1 < heap_last_index && child_index_2 < heap_last_index) {
			child_index_1 = (*(heap + child_index_1) < *(heap + child_index_2)) ? child_index_1 : child_index_2;
			
			if (*(heap + child_index_1) < *(heap + current_index)) {
				swap_by_address (heap + current_index, heap + child_index_1);
				current_index = child_index_1;
			} else {
				break;
			}
		} else if (child_index_1 < heap_last_index && child_index_2 > heap_last_index) {
			if (*(heap + child_index_1) < *(heap + current_index)) {
				swap_by_address (heap + current_index, heap + child_index_1);
				current_index = child_index_1;
			} else {
				break;
			}
		} else if (child_index_1 > heap_last_index && child_index_2 < heap_last_index) {
			if (*(heap + child_index_2) < *(heap + current_index)) {
				swap_by_address (heap + current_index, heap + child_index_1);
				current_index = child_index_2;
			} else {
				break;
			}
		} else {
			break;
		}
	}

	return root_elem;
}

#endif