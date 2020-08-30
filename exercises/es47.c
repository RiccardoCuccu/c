#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]){
	time_t current_time;
	time_t berlin_time;
	struct tm berlin_time_struct;
	double difference;

	berlin_time_struct.tm_year = 1989-1900;
	berlin_time_struct.tm_mon = 11;
	berlin_time_struct.tm_mday = 9;
	berlin_time_struct.tm_hour = 0;
	berlin_time_struct.tm_min = 0;
	berlin_time_struct.tm_sec = 0;
	berlin_time_struct.tm_isdst = 0;

	berlin_time = mktime(&berlin_time_struct);
	time(&current_time);
	difference = difftime(current_time, berlin_time);
	
	printf("Current time = %s", ctime(&current_time));
	printf("%.0f days have passed since the fall of the Berlin Wall.\n", difference/60/60/24);

	return 0;
}