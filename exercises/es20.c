#include <stdio.h>

int main(int argc, char *argv[]) {
	char chr;
	for (chr=65; chr<=122; chr+=1) {
		if (chr > 90 && chr < 97)
			continue;
		printf("[%2d-%c] ", chr, chr);
	}
	printf("\n");
	return 0;
}