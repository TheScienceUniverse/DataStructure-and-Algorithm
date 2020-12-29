#ifndef _HELPER_H
#define _HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int* generate_static_number_list (int list_size) {
	int *list = (int*) malloc (list_size * sizeof (int));
	int b = -1;

	for (int i = 0; i < list_size; i++) {
		*(list + i) = (b *= -1) * (list_size - i);
	}

	return list;
}

int* generate_random_number_list (int list_size) {
	int *list = (int*) malloc (list_size * sizeof (int));
	time_t t;
	// int b = -1;

	srand ((unsigned) time (&t));

	for (int i = 0; i < list_size; i++) {
		// b *= -1;
		*(list + i) = rand(); // * b;
	}

	return list;
}

void print_list (int *list, int list_size) {
	int i;

	printf ("List: ");

	for (i = 0; i < list_size; i++) {
		printf ("%d ", *(list + i));
	}

	printf ("\n\n");
}

void swap_by_address (int *a, int *b) {
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

double get_toughness (int *list, int list_size) {
	double toughness = 0;
	int count = 0;

	for (int i = 0; i < list_size - 1; i++) {
		if (*(list + i) > *(list + i + 1)) {
			++ count;
		} else {
			-- count;
		}
		
	}

	toughness = (100.0 * count / list_size);

	return toughness;
}

#endif