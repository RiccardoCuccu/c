#include <stdio.h>

int main(int argc, char *argv[]) {
	int numbers[5], j;
	int sum = 0;
	printf("Input the first number: "); 
	scanf("%d", &numbers[0]);
	printf("Input the second number: "); 
	scanf("%d", &numbers[1]);
	printf("Input the third number: "); 
	scanf("%d", &numbers[2]);
	printf("Input the fourth number: "); 
	scanf("%d", &numbers[3]);
	printf("Input the fifth number: "); 
	scanf("%d", &numbers[4]);
	for(j=0; j<5; j++) {
		if ((numbers[j]%2) != 0) {
			sum = sum + numbers[j];
		}
	}
	printf("Sum of all odd values: %d\n", sum);
	return 0;
}