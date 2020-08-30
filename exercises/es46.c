#include<stdio.h>

int main(int argc, char *argv[]){
	int i, j, k;
	char str[100];
	char words[10][10];
	printf("Input a string: ");
	fgets(str, sizeof(str), stdin);
	for(i=0, j=0, k=0; i<100; i++) {
		if(str[i]=='\0') {
			break;
		} else if(str[i]==' ' || str[i]=='\n') {
			words[j][k]='\0';
			j++;
			k=0;
		} else {
			words[j][k]=str[i];
			k++;
		}
	}
	printf("Strings or words after split by space are:\n");
	for(i=0; i<j; i++) {
		printf("%s\n", words[i]);
	}
	return 0;
}