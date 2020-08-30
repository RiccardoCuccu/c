#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp;
	int i, n;
	char str[100];
	char fname[20];
	char ch;
 
	printf("Input the file name to be opened: ");
	scanf("%s", fname);
	fp = fopen(fname, "a");
	if (fp == NULL) {
		printf("Errore.\n");
		exit(1);
	} 
	printf("Input the number of lines to be written: ");
	scanf("%d", &n);
	for(i = 0; i<n+1; i++) {
		fgets(str, sizeof(str), stdin);
		fputs(str, fp);
	}
	fclose(fp);

	fp = fopen (fname, "r");
	if (fp == NULL) {
		printf("Errore.\n");
		exit(1);
	} 
	printf("The content of the file %s is:\n", fname);
	ch = fgetc(fp);
	while (ch != EOF) {
		printf ("%c", ch);
		ch = fgetc(fp);
	}
	fclose (fp);

	return 0;
}