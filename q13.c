/* Chapter 5, exercise 14
   Recursive implementation of computing the power (q3) */

#include <stdio.h>
#include <stdlib.h>

/* function prototype */
int pow_rec(int n, int p);

int
main(int argc, char *argv[]) {

	int value, power, result;

	/* get user input and validate it */
	printf("Enter a number and a power to which to raise it: ");
	if (scanf("%d %d", &value, &power) != 2) {
		printf("Invalid input");
		exit(EXIT_FAILURE);
	}

	/* start the funtion */
	result = pow_rec(value, power);
	/* scaffolding */
	printf("%d\n", result);

	return result;

}

/* recursive funtion to raise 'n' to a power of 'p' */
int pow_rec(int n, int p) {

	if (p < 0) {
		/* invalid exponent */
		printf("Negative exponent in pow_rec!\n");
		exit(EXIT_FAILURE);
	} else if (p == 0) {
		/* anything to power of zero is one */
		return 1;
	}

	return n * pow_rec(n, p-1);

}