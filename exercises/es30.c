#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	char buffer[] = "2016 40a0b0 -1101110100110111100110 0x5abfff";
	char *ptr_end;
	long int i1, i2, i3, i4;
	i1 = strtol(buffer,&ptr_end,10);	// decimal
	i2 = strtol(ptr_end,&ptr_end,16);	// esadecimal
	i3 = strtol(ptr_end,&ptr_end,2);	// binary
	i4 = strtol(ptr_end,NULL,0);
	printf ("In decimals: %ld, %ld, %ld, %ld.\n", i1, i2, i3, i4);
	return 0;
}