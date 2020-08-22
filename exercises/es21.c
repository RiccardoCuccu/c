#include <stdio.h>

int main(int argc, char *argv[]) {
	char str1[100], str2[100];
	int i, j;
	printf("Input a string: ");
	scanf("%s", str1);
	for(i=0; str1[i]!='\0'; i++) continue;
	for(j=0; j<i; j++) str2[j]=str1[i-j-1];
	str2[i]='\0';
	printf("Reversed string: %s\n", str2);
	printf("Number of characters is %d\n", i);
	return 0;
}