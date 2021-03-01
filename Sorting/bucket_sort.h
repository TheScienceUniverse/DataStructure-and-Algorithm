#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include "helper.h"

struct node {
	int data;
	struct node *next;
};
typedef struct node Node;

int* bucket_sort (int *list, int list_size) {
	int i, index;

	// pre-processing list...
	int min = *list;	// min => minimum element

	for (i = 1; i < list_size; i++) {
		if (*(list + i) < min) {
			min = *(list + i);
		}
	}

	for (i = 0; i < list_size; i++) {
		*(list + i) -= min;
	}

	// creating bucket...
	Node *bucket = (Node *) malloc (10 * sizeof (Node));

	for (i = 0; i < 10; i++) {
		(bucket + i) -> data = i;
		(bucket + i) -> next = NULL;
	}

	// filling bucket...
	Node *p = NULL;

	for (i = 0; i < list_size; i++) {
		index = *(list + i) % 10;
		p = (bucket + i);

		// adding new data-node to last of the existing list
		while (p -> next != NULL) {
			p = p -> next;
		}

		p -> next = (Node *) malloc (sizeof (Node));
		p = p -> next;
		p -> data = *(list + i);
		p -> next = NULL;
	}

	// printing bucket...
	printf ("bucket:\n");
	for (i = 0; i < 10; i++) {
		printf ("bucket[%d] at %u : ", i);
		p = (bucket + i);
		printf ("%d %u", p -> data, p -> next);
/*
		while (p != NULL) {
			printf ("%d ", p -> data);
			p = p -> next;
		}
*/
		printf ("\n");
	}
	

	// sorting bucket...

	// filling list...

	// post-processing list...

	// freeing bucket...
	free (bucket);

	return list;
}


#endif