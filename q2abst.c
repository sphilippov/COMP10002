#include <stdio.h>
#include <stdlib.h>

#define VALUES 4

int max_2_ints(int n1, int n2);
int max_4_ints(int n1, int n2, int n3, int n4);

int
main(int argc, char *argv[]) {

	int val1, val2, val3, val4, largest;

	/* user input and validation */
	printf("Enter 4 values you wish to compare: ");
	if (scanf("%d%d%d%d", &val1, &val2, &val3, &val4) != VALUES) {
		printf("Invalid input!\n");
		exit(EXIT_FAILURE);
	}

	largest = max_4_ints(val1, val2, val3, val4);

	/* scaffolding to test the function */
	printf("The largest value is %d\n", largest);

	return largest;

}

/* returns the largest integer out of four supplied */
int
max_4_ints(int n1, int n2, int n3, int n4) {

	int pair_one, pair_two, max;

	/* comparing the first pair (n1 and n2) and getting the largest */
	pair_one = max_2_ints(n1, n2);

	/* comparing the second pair (n3 and n4) */
	pair_two = max_2_ints(n3, n4);

	/* comparing the two largest values out of both pairs */
	max = max_2_ints(pair_one, pair_two);

	return max;

}

/* returns the largest integer out of two supplied */
int
max_2_ints(int n1, int n2) {

	int biggest;

	if (n1 > n2) {
		biggest = n1;
	} else {
		biggest = n2;
	}

	return biggest;

}

