#include<stdio.h>

int main(int argc, char *argv[]) {
	int h, m, h_degree, m_degree, angle;
	printf("Input hour(h) and minute(m) (separated by a space): ");
	scanf("%d %d", &h, &m);
	if(h<0 || h>23 || m<0 || m>59) {
		printf("The hours value must be between 0 and 23 while the minutes value must be between 0 and 59.\n");
		return 1;
	}
	if(h>12) {
		h-=12;
	}
	h_degree=h*30;
	m_degree=m*6;
	angle=h_degree-m_degree;
	if(angle==360 || angle==-360) {
		angle=0;
	}
	printf("The angle is %d degrees at %02d:%02d.\n", angle, h, m);
	return 0;
}