/* Chapter 5, question 6 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int amicable(int a, int b);
int sumfactors(int n);

/* AMICABLE PAIR is a pair of numbers with their factors being equal */
int
main(int argc, char *argv[]) {
	int n1, n2, ami;

	/* get two numbers */
	printf("Enter two numbers: ");
	if (scanf("%d%d", &n1, &n2)!=2) {
		printf("Invalid input\n");
		exit(EXIT_FAILURE);
	}

	ami = amicable(n1, n2);

	/* scaffolding */
	printf("Return: %d", ami);

	return ami;

}

int
amicable(int a, int b) {

	int a_factors, b_factors;

	/* find sum of factors for each number */
	a_factors = sumfactors(a);
	b_factors = sumfactors(b);

	/* compare the sum of factors */
	if (a_factors == b_factors) {
		/* scaffolding */
		printf("%d and %d are an amicable pair.\n", a, b);
		return TRUE;
	} else {
		/* scaffolding */
		printf("The pair is not an amicable pair.\n");
		return FALSE;
	}
	
}

/* sum the factors of the argument */
int
sumfactors(int n) {
	int i, sum=1;
	/* the sum already includes the first factor */
	for (i=2; i*i<n; i++) {
		/* the loop is much more efficient if stopped at sqrt(n) */
		if (n%i==0) {
			/* found a factor */
			sum += i;
			/* and get two for the price of one */
			sum += (n/i);
		}
	}
	/* one more thing to check, that last value of i */
	if (i*i==n) {
		/* yes, n is a square, and has one more factor */
		sum += i;
	}
	return sum;
}