#include<stdio.h>

int main(int argc, char *argv[]){
	char str1[100], str2[100], str3[200];
	int i=0, j=0;
	printf("Input the first string: ");
	fgets(str1, sizeof(str1), stdin);
	printf("Input the second string: ");
	fgets(str2, sizeof(str2), stdin);
	while (str1[i]!='\n') {
		str3[i]=str1[i];
		i++;
	}
	while (str2[j]!='\0') {
		str3[i+j]=str2[j];
		j++;
	}
	str3[i+j]='\0';
	printf("After concatenation the string is: %s", str3);
	return 0;
}