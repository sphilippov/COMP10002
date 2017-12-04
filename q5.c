/* Chapter 5, exercise 5 */
/* 6, 28, 496, 8128, 33550336 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* function prototype */
int isperfect(int n);
int nextperfect(int n);
int sumfactors(int n);
void printperfect();

/* a PERFECT number is equal to the sum of its factors (excluding itself) */
int
main(int argc, char *argv[]) {

	int v, next_perfect;

	/* get a number */
	printf("Enter a number: ");
	if ((scanf("%d", &v)!=1) || (v<0)) {
		printf("Invalid input");
		exit(EXIT_FAILURE);
	}

	/* check if it is a perfect number */
	if(isperfect(v)) {
		printf("%d is a perfect number\n", v);
	} else {
		printf("%d is not a perfect number\n", v);
	}
	

	/* find the next perfect number bigger than v */
	next_perfect = nextperfect(v);
	printf("The next perfect number is %d\n", next_perfect);

	/* print all perfect numbers (to terminate ^C) */
	printperfect();

	return 0;
}

/* returns TRUE (1) if n is a perfect number; FALSE otherwise */
int 
isperfect(int n) {

	int factor_sum;

	/* find the sum of factors for n */
	factor_sum = sumfactors(n);

	if (n == factor_sum) {
		/* n is a perfect number */
		return TRUE;
	} else {
		return FALSE;
	}

}

/* returns the next perfect number greater than n */
int 
nextperfect(int n) {

	int next = n + 1;
	/* */
	while (!isperfect(next)) {
		next++;
	}

	return next;

}

/* searches and prints all perfect numbers */
void
printperfect() {

	printf("Now looking for all perfect numbers starting from 1\n");

	/* count how many perfect numbers have been found */
	int count = 0, number = 1;

	/* limiting the loop to 6 perfect numbers */
	while (count<6) {

		/* check if number is perfect */
		if (number == sumfactors(number)) {

			/* printing the number */
			printf("%d\n", number);
			count++;

			
		}
		number++;
		/* looking for the next perfect number */
		nextperfect(number+1);

	}

}

/* find all factors of n and sum them (not including n) */
int
sumfactors(int n) {

	int sum = 0;

	/* first, find all factors for n */
	for (int i=1; i<n; i++) {

		if (n%i == 0) {
			/* i is a factor */
			sum += i;
		}

	}

	return sum;

}
