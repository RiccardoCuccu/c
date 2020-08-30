#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp;
	char c;
	fp=fopen("./work/canto.txt", "r");
	if (fp == NULL) {
		printf("Errore");
		exit(1);
	}
	while(1) {
		c=fgetc(fp);
		if(c==EOF)
			break;
		else if (c==' ')
			continue;
		else
			putchar(c);
	}
	printf("\n");
	fclose(fp);
	return 0;
}