#include <stdio.h>

int main(int argc, char *argv[]) {
	int days, years, weeks;
	printf("Enter the number of days: ");
	scanf("%d", &days);
	years = days/365; 
	weeks = (days%365)/7;
	days = days-((years*365)+(weeks*7));
	printf("Years: %d\n", years);
	printf("Weeks: %d\n", weeks);
	printf("Days: %d \n", days);
	return 0;
}