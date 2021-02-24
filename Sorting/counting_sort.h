#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "helper.h"

int* counting_sort (int *list, int list_size) {
	int i, j, x;
	int min = *(list + 0), max = *(list + 0);

	for (i = 1; i < list_size; i++) {
		if (*(list + i) > max)
			max = *(list + i);
		if (*(list + i) < min)
			min = *(list + i);
	}

	x = 0 - min, max = max + x + 1;

	if (max > 1000) {
		perror ("ERROR: List too long...max element : 1000\n");
		return list;
	}

	for (i = 0; i < list_size; i++) {
		*(list + i) += x;
	}

	int *temp = (int *) calloc (max, sizeof (int));

	for (i = 0; i < list_size; i++) {
		++ *(temp + *(list + i));
	}

	j = 0;

	for (i = 0; i < max; i++) {
		if (*(temp + i) > 0) {
			do {
				-- *(temp + i);
				*(list + j++) = i;
			} while (*(temp + i) > 0);
		}
	}

	for (i = 0; i < list_size; i++) {
		*(list + i) -= x;
	}

	return list;
}

#endif