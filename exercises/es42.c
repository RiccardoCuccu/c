#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[]) {
	char str[100];
	int len, ch, i;
	printf("Input the string: ");
	fgets(str, sizeof(str), stdin);  
	len=strlen(str);
	printf("After case changed the string is: ");
	for(i=0; i<len; i++) {
		if (islower(str[i]))
			ch=toupper(str[i]);
		else
			ch=tolower(str[i]);
		putchar(ch);
	}
	return 0;
}