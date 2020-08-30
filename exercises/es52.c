#include<stdio.h>
#include<stdlib.h>
#define K 100

int main(int argc, char *argv[]){
	FILE *fp, *ft;
	char fname[20], ch;
	
	printf("Input the name of file to encrypt: ");
	scanf("%s",fname);	

	fp=fopen(fname, "r");
	if(fp==NULL) {
		printf("File does not exists or error in opening!\n");
		exit(1);
	}
	ft=fopen("temp.txt", "w");
	if(ft==NULL) {
		printf("Error in creation of file temp.txt!\n");
		exit(2);
	}
	while(1) {
		ch=fgetc(fp);
		if(ch==EOF) {
			break;
		} else {
			ch=ch-K;
			fputc(ch, ft);
		}
	}
	fclose(fp);
	fclose(ft);

	fp=fopen(fname, "w");
	if(fp==NULL)
	{
		printf("File does not exists or error in opening!\n");
		exit(3);
	}

	ft=fopen("temp.txt", "r");
	if(ft==NULL) {
		printf("File does not exists or error in opening!\n");
		exit(4);
	}
	while(1) {
		ch=fgetc(ft);
		if(ch==EOF) {
			break;
		} else {
			fputc(ch, fp);
		}
	}
	printf("File %s successfully encrypted!\n", fname);
	fclose(fp);
	fclose(ft);
	remove("temp.txt");
}