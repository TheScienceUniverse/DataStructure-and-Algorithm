#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

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

#endif