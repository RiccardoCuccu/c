#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]) {
	int number, input;
	/* Initialize random seed */
	srand(time(NULL));
	/* Generate a random number between 1 and 10 */
	number = rand() % 10 + 1;
	do {
		printf("Guess the number (1 to 10): ");
		scanf("%d",&input);
		if (number > input)
			printf ("The number is higher.\n");
		else if (number < input)
			printf ("The number is lower.\n");
	} while (number!=input);
	printf("That is correct!\n");
	return 0;
}