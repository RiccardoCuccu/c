#include<stdio.h>

struct EmpAddress {
	char *ename;
	char stname[20];
	int pincode;
} employee={"John Alter", "Court Street", 654134}, *pt=&employee;

int main(int argc, char *argv[]) {
	printf("Pointer: show the usage of pointer to structure:\n"); 
	printf("--------------------------------------------------------\n");
	printf("%s from %s => Personal PIN: %d\n", pt->ename, (*pt).stname, pt->pincode);
	return 0;
}