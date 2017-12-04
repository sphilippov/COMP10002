/* Chapter 5, exercise 8 
   The program checks for a rounding error, allowing for a small tolerance;
   and returns true if the two arguments are either both exactly equal to
   zero, or are within 0.01% 
   found online: [ABS((MAX(A2,B2)-MIN(A2,B2))/MIN(A2,B2))<0.01] */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

/* function prototype */
int near_equal(double v1, double v2);

int
main(int argc, char *argv[]) {

	double v1, v2;
	int equality;

	/* get two numbers and check the validity of input */
	if (scanf("%lf%lf", &v1, &v2) != 2) {
		printf("Invalid Input\n");
		exit(EXIT_FAILURE);
	}

	/* compare for equality */
	equality = near_equal(v1, v2);

	printf("%d\n", equality);
	return equality;
}

int
near_equal(double v1, double v2) {

	double max, min;

	/* find max and min of there two values */
	if (v1 > v2) {
		max = v1;
		min = v2;
	} else {
		max = v2;
		min = v1;
	}

	/* first, checking for the cases of total equality and non-equality */
	if ((v1 == 0.0) && (v2 == 0.0)) {
		/* both values equal to zero */
		return TRUE;
	} else if (fabs((max-min)/min)<0.01) {
		/* near to equal */
		return TRUE;
	} else if (v1*v2 == 0.0) {
		/* one of the values is zero; hence not equal */
		return FALSE;
	} else {
		return FALSE;
	}

}

