#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp, *ft;
	int i, flag=0;
	char fname[]="./work/results.txt";
	char fdouble[]="double.txt";
	double v[6];
	char c[6];

	fp=fopen(fname, "r");
	if(fp==NULL) {
		printf("File does not exists or error in opening!\n");
		exit(1);
	}
	ft=fopen(fdouble, "w");
	if(ft==NULL) {
		printf("Error in creation of file %s!\n", fdouble);
		exit(2);
	}

	while(!feof(fp)) {
		if(flag==0){
			flag++;
			fscanf(fp, "%c\t%c\t%c\t%c\t%c\t%c\n", &c[0], &c[1], &c[2], &c[3], &c[4], &c[5]);
			//fprintf(ft, "%c\t%c\t%c\t%c\t%c\t%c\n", c[0], c[1], c[2], c[3], c[4], c[5]);
		} else {
			fscanf(fp, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf", &v[0], &v[1], &v[2], &v[3], &v[4], &v[5]);
			for(i=0; i<6; i++) {
				v[i]=v[i]*2;
			}
			fprintf(ft, "%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n", v[0], v[1], v[2], v[3], v[4], v[5]);
		}
	}

	fclose(fp);
	fclose(ft);

	return 0;
}