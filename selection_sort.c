#include <stdio.h>

void selection_sort(int A[], int n);

int
main(int argc, char *argv[]) {
	int temp, n, i = 0;

	printf("Enter the number of values in the array: ");
	scanf("%d", &n);
	int A[n];
	printf("Enter n number of elements: ");
	
	while (scanf("%d", &temp)==1) {
		A[i] = temp;
		i++;
	}

	for (int j=0; j<n; j++) {
		printf("%d", A[j]);
	}
}

void
selection_sort(int A[], int n) {

}