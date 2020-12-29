#include "helper.h"
#include "sort.h"

int main (void) {
	int n;
	clock_t t1, t2;
	int *L, *S;
	
	printf ("Please enter list size (Max = 10000): ");
	scanf ("%d", &n);

	// L = generate_random_number_list (n);
	L = generate_static_number_list (n);
	double toughness = get_toughness (L, n);

	print_list (L, n);
	t1 = clock();
	S = quick_sort (L, n);
	t2 = clock();
	print_list (S, n);
	// printf ("Approximate time taken %lf seconds for %lf %% toughness\n", (double) (t2 - t1) / CLOCKS_PER_SEC, toughness);

	free (L);
	free (S);

	return 0;
}