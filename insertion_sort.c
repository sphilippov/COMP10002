#include <stdio.h>

#define LIMIT 1000

void int_swap(int *p1, int *p2);
void print_array(int A[], int c, char *str);
int distinct(int A[], int n);

int
main(int argc, char *argv[]) {
	int A[LIMIT], i, j, value, count = 0;

	/* writing the values in */
	printf("Enter as many as 1000 values, ^D to end: ");
	while (scanf("%d", &value)==1) {
		A[count] = value;
		count++;
	}
	printf("%d values read into array\n", count);
	print_array(A, count, "Before");

	/* assume that A[0] to A[n-1] have valid values */
	for (i=1; i<count; i++) {
		/* swap A[i] left into correct position */
		for (j=i-1; j>=0 && A[j+1]<A[j]; j--) {
			int_swap(&A[j], &A[j+1]);
		}
	}
	print_array(A, count, "After");
	int x = distinct(A, count);
	printf("%d distinct values\n", x);
	print_array(A, x, "Distinct");

}

void
int_swap(int *p1, int *p2) {
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/* printing array before or after */
void
print_array(int A[], int n, char *str) {

	printf("%8s: ", str);
	for (int i=0; i<n; i++) {
		printf("%2d ", A[i]);
	}
	printf("\n");
}

int
distinct(int A[], int n) {

	int index = 1;

	for (int i=0; i<n-1; i++) {
		if (A[i]!=A[i+1]) {
			A[index] = A[i+1];
			index++;
		}
	}
	return index;

}
