/* Chapter 5, exercise 7
   My own implementation of "isupper" and "tolower" functions
   --> "isupper" returns a non-zero value(true) if c is an uppercase alphabetic
   letter else, zero (false) 
   --> "tolower" returns lowercase equivalent to c, if such value exists, else 
   c remains unchanged. The value is returned as an int value that can be 
   implicitly casted to char 
   Definitions are taken from tutorialspoint.com */

#include <stdio.h>
#include <stdlib.h>

#define LOWER_A 'a'
#define UPPER_A 'A'
#define UPPER_Z 'Z'

#define TRUE 1
#define FALSE 0

/* function prototypes */
int my_isupper(int c);
int my_tolower(int c);

int
main(int argc, char *argv[]) {

	int c;

	/* get the user input and check its validity */
	printf("Enter some text, ^D to end:\n");
	while ((c=getchar()) != EOF) {

		/* 'c' is uppercase */
		if (my_isupper(c)) {
			/* convert to lower */
			c = my_tolower(c);

		}
		/* 'c' is lowercase */
		putchar(c);
	}

	return 0;

}

/* returns TRUE if a character is an uppercase */
int
my_isupper(int c) {

	/* uppercase: A-Z; checking if c is in the upper range.
	   characters are really just integers in a limited range,
	   and can be compared as integers. Note that arguments to
	   character manipulation functions are declared as int */
	if ((c >= UPPER_A) && (c <= UPPER_Z)) {

		return TRUE;

	} else {

		return FALSE;
	}


}

/* converts a character to a lowercase */
int
my_tolower(int c) {

	/* check if 'c' is actually a lowercase */
	if (my_isupper(c)) {
		/* convert and return the lowercase equavalent */
		return (c - UPPER_A + LOWER_A);
	} else {
		/* return the same value */
		return c;
	}

	
}
