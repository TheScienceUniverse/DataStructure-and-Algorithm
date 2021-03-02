#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "helper.h"
#include "insertion_sort.h"

struct node {
	int data;
	struct node *next;
};
typedef struct node Node;

int* radix_sort (int*, int);
void show_buckets (Node*);
void clear_buckets (Node*);
int count_digits (int);
int get_bucket_index_to_insert (int, int);

int* radix_sort (int *list, int list_size) {
	int i;

	// pre-processing list...
	int min = *list;	// min => minimum element

	for (i = 1; i < list_size; i++) {
		if (*(list + i) < min) {
			min = *(list + i);
		}
	}

	// get max digit count
	int max_digits, x = 0;

	for (i = 0; i < list_size; i++) {
		*(list + i) -= min;
		x = count_digits (*(list + i));

		if (x > max_digits) {
			max_digits = x;
		}
	}

	// creating buckets list...
	Node *buckets = (Node *) malloc (10 * sizeof (Node));

	for (i = 0; i < 10; i++) {
		(buckets + i) -> data = i;
		(buckets + i) -> next = NULL;
	}

	// [filling buckets, sorting bucket, copying buckets] * [max_digits times]...
	Node *p;
	int index, temp_size, j;
	int *temp = (int *) calloc (list_size, sizeof (int));
	int digit_index = 0;

	while (digit_index < max_digits) {
		// fill buckets with list values
		for (i = 0; i < list_size; i++) {
			index = get_bucket_index_to_insert (*(list + i), digit_index);
			p = (buckets + index);

			while (p -> next != NULL) {
				p = p -> next;
			}

			p -> next = (Node *) malloc (sizeof (Node));
			p = p -> next;
			p -> data = *(list + i);
			p -> next = NULL;
		}

		// show buckets
		// show_buckets (buckets);

		index = 0;

		// re-fill list
		for (i = 0; i < 10; i++) {
			// storing in temporary list from each bucket
			p = (buckets + i) -> next;
			temp_size = 0;

			while (p != NULL) {
				*(temp + temp_size++) = p -> data;
				p = p -> next;
			}

			// sorting temporary list for each bucket
			temp = insertion_sort (temp, temp_size);
			
			// copying data to original list from temporary list for each bucket
			for (j = 0; j < temp_size; j++) {
				*(list + index++) = *(temp + j);
			}
		}

		clear_buckets (buckets);
		++digit_index;		
	}

	// post-processing list...
	for (i = 0; i < list_size; i++) {
		*(list + i) += min;
	}

	// freeing bucket...
	free (buckets);
	free (temp);

	return list;
}

void show_buckets (Node *buckets) {
	int i;
	Node *p;

	for (i = 0; i < 10; i++) {
		p = (buckets + i) -> next;
		printf ("bucket-%d: ", i);

		while (p != NULL) {
			printf ("%d ", p -> data);
			p = p -> next;
		}

		printf ("\n");
	}
}

void clear_buckets (Node *buckets) {
	int i;
	Node *p, *q;

	for (i = 0; i < 10; i++) {
		p = (buckets + i) -> next;
		(buckets + i) -> next = NULL;

		while (p != NULL) {
			q = p;
			p = p -> next;
			free (q);
		}
	}

	//free (p);
	//free (q);
}

int count_digits (int number) {
	int count = 0;

	if (number == 0) {
		count = 1;
	}

	while (number != 0) {
		++count;
		number /= 10;
	}

	return count;
}

int get_bucket_index_to_insert (int number, int digit_index) {
	while (digit_index-- >= 1) {
		number /= 10;
	}

	return (number % 10);
}

#endif
