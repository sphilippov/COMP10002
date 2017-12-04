/* Chapter 5, exercise 14 
   Application of log* (log star) */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* function prototype */
double log_base2(double a);
int log_star(double a);

/* log* - the number of times that you can take the logarithm of its argument
   before getting a value less than one */
int
main(int argc, char *argv[]) {

	double value;

	/* get a value from the input */
	printf("Enter a value: ");
	if (scanf("%lf", &value) != 1) {
		printf("Invalid input\n");
		exit(EXIT_FAILURE);
	}

	/* scaffolding to test the final result */
	printf("log base 2 of %.1f is %.3f\n", value, log_base2(value));
	printf("logstar    of %.1f is %d\n", value, log_star(value));
	return 0;

}

/* find log of base 2 */
double
log_base2(double a) {
	return log(a)/log(2.0);
}

/* recursive function that returs the log* */
int
log_star(double a) {

	if (a < 1.0) {
		return 0;
	} else {
		return 1 + log_star(log_base2(a));
	}
}