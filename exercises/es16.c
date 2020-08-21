#include <stdio.h>

int main (int argc, char *argv[]) {
	int x, reminder, reverse = 0;
	printf("Input a number: ");
	scanf("%d", &x);
	while (x>0) {
		reminder = x%10;
		reverse = reverse*10 + reminder;
		x = x/10;
	}
	printf("The reverse of the said number is %d\n", reverse);
	return 0;
}