#include <stdio.h>

int main(int argc, char *argv[]) {
	int height, width, perimeter, area;
	printf("Enter the height: ");
	scanf("%d", &height);
	printf("Enter the width: ");
	scanf("%d", &width);
	perimeter = (height+width)*2;
	area = height*width;
	printf("The perimeter is: %d inches\n", perimeter);
	printf("The area is: %d square inches\n", area);
	return 0;
}