#include<stdio.h>

int main(int argc, char *argv[]) {
	int m=10, n, o;
	int *z=&m;
	/* & returns the memory address of a variable 
	   this can only be allocated within a pointer (*) type variable */
	printf("Pointer: show the basic declaration of pointer :\n");
	printf("-------------------------------------------------------\n"); 
	printf("Here is m=10, n and o are two integer variable and *z is an integer\n\n");
	/* z is a pointer, so %p would print the address */	
	printf("z stores the address of m = %p\n", z); 
	printf("*z stores the value of m = %i\n", *z);
	/* &m gives the address of the integer variable m 
	   so %p is the specifier for that address */
	printf("&m is the address of m = %p\n", &m); 
	printf("&n stores the address of n = %p\n", &n);
	printf("&o stores the address of o = %p\n", &o);
	/* &z gives the address, where the pointer z is 
	   stored -> still an address -> %p is the right specifier */
	printf("&z stores the address of z = %p\n", &z); 
	return 0;
}