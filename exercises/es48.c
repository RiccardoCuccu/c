#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp;
	char string[100];
	fp=fopen("./work/text.txt", "w");
	if (fp == NULL) {
		printf("Errore.\n");
		exit(1);
	}
	printf("Input a string for the file: ");
	fgets(string, sizeof(string), stdin);
	fprintf(fp, "%s", string);
	fclose(fp);

	printf("File created successfully!\n");

	return 0;
}