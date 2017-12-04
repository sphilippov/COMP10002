#include <stdio.h>

#define MAX 10

/* function prototypes */
int all_zero(int A[], int n);
int read_int_array(int A[], int n);
void print_int_array(int A[], int n);

int
main(int argc, char *argv[]) {

	int array[MAX], valid;

	/* read in an array, and return number of items */
	valid = read_int_array(array, MAX);

	/* print the array */
	printf("The array:\n");
	print_int_array(array, valid);
		
	/* check for all zero array */
	if (all_zero(array, valid)) {
		printf("all zeros!\n");
	} else {
		printf("some non-zero values found!\n");
	}

	return 0;
}

/* returns TRUE(1) if all elements are zero; and FALSE(0) if any of the elements are non-zero */
int
all_zero(int A[], int n) {

	for (int i=0; i<n; i++) {
		if (A[i]) {
			printf("return 0\n");
			return 0;
		}
	}

	/* all items are 0 */
	printf("return 1\n");
	return 1;
}

/* record the array */
int
read_int_array(int A[], int max_items) {

	int n = 0;
	int next, excess = 0;

	printf("Enter up to %d values; and press ^D to end the array\n", max_items);
	while (scanf("%d", &next) == 1) {
		if (n == max_items) {
			excess++;
		} else {
			A[n] = next;
			n++;
		}
	}

	printf("%d item(s) entered\n", n);
	if (excess) {
		printf(", %d excess item(s) disregarded.\n", excess);
	}

	return n;

}

void
print_int_array(int A[], int n) {

	for (int i=0; i<n; i++) {
		printf("%d", A[i]);
	}
	printf("\n");
}
