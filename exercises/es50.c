#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp, *ft;
	int i=1, n;
	char ch;
	char buffer[100];
	char fname[20] = "test.txt";
	char ftemp[20] = "temp.txt";

	printf("Input the content of the new line: ");
	fgets(buffer, sizeof(buffer), stdin);
	printf("Input the line number you want to replace: ");
	scanf("%d", &n);

	fp = fopen(fname, "r");
	ft = fopen(ftemp, "w");
	if (fp == NULL || ft == NULL) {
		printf("Errore.\n");
		exit(1);
	}

	ch = fgetc(fp);
	while(ch!=EOF){
		if(ch=='\n') {
			if (i==n) {
				fprintf(ft, "%s", buffer);
			} else {
				fputc(ch, ft);
			}
			ch=fgetc(fp);
			i++;
		} else if (i==n) {
			ch=fgetc(fp);
			continue;
		} else {
			fputc(ch, ft);
			ch=fgetc(fp);
		}
	}

	fclose(fp);
	fclose(ft);

	fp = fopen(fname, "w");
	ft = fopen(ftemp, "r");
	if (fp == NULL || ft == NULL) {
		printf("Errore.\n");
		exit(1);
	}

	ch = fgetc(ft);
	while (ch != EOF) {
		fputc(ch, fp);
		ch = fgetc(ft);
	}

	fclose(fp);
	fclose(ft);
	remove(ftemp);

	return 0;
}