#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float mid = 0, end = 0;

	printf("mid = ");
	scanf("%f", &mid);

	printf("end = ");
	scanf("%f", &end);

	float avg = mid * 0.3 + end * 0.7;
	printf("avg = %.2f\n", avg);

	return 0;
}