/* Chapter 6, exercise 5 */

#include <stdio.h>
#include <stdlib.h>
	
void int_sort2(int *p1, int *p2);

int
main(int argc, char *argv[]) {

	int num1, num2;

	/* get the two numbers and the check validity of the input*/
	printf("Enter two numbers to sort: ");
	if (scanf("%d %d", &num1, &num2) != 2) {
		printf("Invalid input\n");
		exit(EXIT_FAILURE);
	}
	printf("Before: num1 = %d, num2 = %d\n", num1, num2);

	/* calling the function to sort the numbers */
	int_sort2(&num1, &num2);

	printf("After: num1 = %d, num2 = %d\n", num1, num2);
	return 0;

}

/* numerically smaller value is placed into the underlying variable corresponding to the first argument pointer */
void
int_sort2(int *p1, int *p2) {

	int temp;
	if (*p1 > *p2) {
		/* swap required */
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	} else {
		printf("Swap is not required\n");
		return;
	}

}
