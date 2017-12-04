/* Chapter 5, exercise 11 */

#include <stdio.h>
#include <stdlib.h>

/* function prototype */
double sum_sequence(int n);
int factorial(int n);
int add_terms(int n);

int 
main(int argc, char const *argv[]) {

	int n;
	double result;

	/* user input and validation */
	printf("Enter a number: ");
	if (scanf("%d", &n) != 1) {
		printf("Invalid input\n");
		exit(EXIT_FAILURE);
	}

	/* calculate the sequence sum */
	result = sum_sequence(n);

	/* scaffolding to test the result of the program */
	printf("result: %lf\n", result);

	return result;
}

/* calculates and returns the sum of a sequence [(1+2+...+n)/n!], where n is
   a positive integer argument */
double
sum_sequence(int n) {

	double numerator, denominator, sum, fraction;

	/* calculate the sum */
	numerator = denominator = sum = fraction = 0.0;
	for (int i=1; i<=n; i++) {
		/* adding up to find the numerator */
		numerator = add_terms(i);

		/* finding a factorial of 'i' for current iteration */
		denominator = factorial(i);

		/* sum for previous + current iteration */
		fraction = numerator/denominator;
		sum += fraction;

		/* scaffolding to test numerator, denominator, their fraction and the 
		sum of that fraction on each iteration of the loop */
		printf("iter: %d | num (added sequence): %lf, denum (factorial): %lf\n",
		 i, numerator, denominator);
		printf("fraction: %lf | sum: %.3lf\n", fraction, sum);
	}

	return sum;

}

/* calculates factorial of n */
int
factorial(int n) {

	int fact, product;

	fact = product = 1;
	/* multiplying a sequence of numbers untill 'n' */
	while (product <= n) {
		fact *= product;
		product++;
	}

	return fact;

}

/* adding a squence of numbers from one to 'n' */
int
add_terms(int n) {

	int current, total;

	current = total = 0;
	while (current <= n) {
		total += current;
		current++;
	}	

	return total;

}
