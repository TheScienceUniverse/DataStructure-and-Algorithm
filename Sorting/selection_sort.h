#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

int* selection_sort (int *list, int list_size) {
	int i, j, x;
	int min_idx;    // minimum index

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

#endif