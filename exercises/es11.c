#include <stdio.h>

int main (int argc, char *argv[]) {
	int password = 1234;
	int input = 0;
	while (input != password) {
		printf("Input the password: ");
		scanf("%d", &input);
		if (input != password) {
			printf("Incorrect password!\n");
		}
	}
	printf("Correct password!\n");
	return 0;
}