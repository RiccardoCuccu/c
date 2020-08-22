#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int radius;
	float perimeter, area;
	printf("Enter the radius: ");
	scanf("%d", &radius);
	perimeter = 2*M_PI*radius;
	area = M_PI*radius*radius;
	printf("The perimeter is: %f inches\n", perimeter);
	printf("The area is: %f square inches\n", area);
	return 0;
}