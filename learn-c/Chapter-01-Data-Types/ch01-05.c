#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.14

int main()
{
	float r = 0;

	printf("r = ");
	scanf("%f", &r);

	float c = 2 * r * PI;
	float s = r * r * PI;

	printf("c = %.2f\n", c);
	printf("s = %.2f\n", s);

	return 0;
}