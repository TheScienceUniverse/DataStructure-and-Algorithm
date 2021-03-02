#ifndef COMB_SORT_H
#define COMB_SORT_H

#include "helper.h"

int* comb_sort (int*, int);

int* comb_sort (int *list, int list_size) {
	int gap = list_size;	// initialize gap size
	float shrink = 1.3;		// gap shrink factor by Włodzimierz Dobosiewicz and Artur Borowy
	int sorted_flag = 0;	// 0 => false, 1 => true

	while (!sorted_flag) {
		// Update the gap value for a next comb
		gap /= shrink; // for int, (gap / shrink) => floor (gap / shrink)

		if (gap <= 1) {
			gap = 1;
			sorted_flag = 1; // If there are no swaps this pass, we are done
		}

		// A single "comb" over the input list
		int i = 0;

		while (i + gap < list_size) { 
			if (*(list + i) > *(list + i + gap)) {
				swap_by_address ((list + i), (list + i + gap));
				sorted_flag = 0;
			}

			i = i + 1;
		}
	}
	return list;
}

#endif