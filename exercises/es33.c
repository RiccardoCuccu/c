#include<stdio.h>

int main(int argc, char *argv[]) {
	int array[100];
	int n, i, j, temp;
	printf("Input the number of elements to be stored in the array: ");
	scanf("%d", &n);
	printf("Input %d elements in the array:\n", n);
	for(i=1; i<=n; i++) {
		printf("Element %d: ", i);
		scanf("%d", &array[i-1]);
	}
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if (array[j] > array[i]) {
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	for(i=1; i<=n; i++) {
		printf("Sorted element %d: %d\n", i, array[i-1]);
	}
	return 0;
}