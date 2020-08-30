#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp;
	int i, n;
	char str[100];
	char fname[20]="test.txt";
	char ch;

	printf("Input the number of lines to be written: ");
	scanf("%d", &n);

	fp = fopen(fname, "w");
	for(i=0; i<n+1; i++) {
		fgets(str, sizeof(str), stdin);
		fputs(str, fp);
	}
	fclose(fp);

	fp = fopen(fname, "r");
	printf("The content of the file %s is:", fname);
	ch = fgetc(fp);
	while (ch != EOF) {
		printf ("%c", ch);
		ch = fgetc(fp);
	}
	fclose(fp);

	return 0;
}