#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "helper.h"

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

#endif