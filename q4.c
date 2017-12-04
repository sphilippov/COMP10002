/* Chapter 5, exercise 4 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* function protorype */
int n_choose_k(int n, int k);
int factorial(int v);

int
main(int argc, char *argv[]) {

	int n, k, c;
	/* user input */
	printf("Enter n and k: ");
	if (scanf("%d %d", &n, &k)!=2) {
		printf("Error in input\n");
		exit(EXIT_FAILURE);
	}

	c = n_choose_k(n, k); 
	printf("%d\n", c);

	return c;
}

/* finds the number of ways of selecting a k item subset of n distinct items */
int 
n_choose_k(int n, int k) {

	int x, fact_n, fact_k, fact_x, result;

	/* finding factorials of each value */
	fact_n = factorial(n);
	fact_k = factorial(k);

	x = n - k;
	fact_x = factorial(x);

	/* calculating the value c base on the formula */
	result = fact_n/(fact_x*fact_k);
	
	return result;

}

/* calculates a factorial of some value */
int
factorial(int v) {

	int factor = 1;

	for (int i=2; i<=v; i++) {
		/* need to be very careful here, as it is easy for
		   factorial calculation to overflow int arithmetic */
		if (i >= INT_MAX/factor) {
			/* equivalent to fact*i>=INT_MAX */
			printf("Integer overflow problem\n");
			exit(EXIT_FAILURE);
		}
		factor *= i;
	}

	return factor;

}