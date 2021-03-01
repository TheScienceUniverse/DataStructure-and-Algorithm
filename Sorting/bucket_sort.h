#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include "helper.h"
#include "sort.h"

struct node {
	int data;
	struct node *next;
};
typedef struct node Node;

int* bucket_sort (int*, int);
void show_buckets (Node*);
int count_digits (int);
int get_bucket_index_to_insert (int, int);

int* bucket_sort (int *list, int list_size) {
	int i;

	// pre-processing list...
	int min = *list;	// min => minimum element

	for (i = 1; i < list_size; i++) {
		if (*(list + i) < min) {
			min = *(list + i);
		}
	}

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

	// filling buckets...
	Node *p;
	int index;

	for (i = 0; i < list_size; i++) {
		index = get_bucket_index_to_insert (*(list + i), max_digits);
		p = (buckets + index);

		// adding new data-node to last of the existing list
		while (p -> next != NULL) {
			p = p -> next;
		}

		p -> next = (Node *) malloc (sizeof (Node));
		p = p -> next;
		p -> data = *(list + i);
		p -> next = NULL;
	}

	// printing buckets...
	show_buckets (buckets);

	// sorting buckets and filling list...
	int *temp = (int *) calloc (list_size, sizeof (Node));
	int temp_size, j;

	index = 0;

	for (i = 0; i < 10; i++) {
		p = (buckets + i) -> next;
		temp_size = 0;

		while (p != NULL) {
			*(temp + temp_size++) = p -> data;
			p = p -> next;
		}

		temp = merge_sort (temp, temp_size);
		
		for (j = 0; j < temp_size; j++) {
			*(list + index++) = *(temp + j);
		}
	}

	// post-processing list...
	for (i = 0; i < list_size; i++) {
		*(list + i) += min;
	}

	// freeing bucket...
	free (buckets);

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

int get_bucket_index_to_insert (int number, int max_digits) {
	while (max_digits-- > 1) {
		number /= 10; 
	}

	return (number % 10);
}

#endif