/* Chapter 5, exercise 3 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ENTRY 2

/* function prototype */
int int_pow(int base, int exponent);

int
main(int argc, char *argv[]) {

	int val, pow, result;

	/* user input and validation */
	printf("Enter an argument value and the power: ");
	if ((scanf("%d %d", &val, &pow) != ENTRY) || (pow < 0)) {
		printf("Invalid input\n");
		exit(EXIT_FAILURE);
	}

	result = int_pow(val, pow);

	/* scaffolding */
	printf("The result of raising %d to the power of %d is %d\n",
		val, pow, result);

	return result;
}
	
/* function raises its first argument to the power of its second argument */
int
int_pow(int base, int exponent) {

	int product = base;

	for (int i=1; i<exponent; i++) {
		/* beware of overflow, have to test via division */
		if ((base!=0) && (abs(INT_MAX/base)<abs(power))) { 
			printf("Integer overflow in int_pow\n");
			exit(EXIT_FAILURE);
		}
		/* safe */
		product *= base;
	}

	return product;

}