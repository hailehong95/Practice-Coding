#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float a, b;
	printf("Enter two numbers: ");
	scanf("%f %f", &a, &b);

	printf("%.1f + %.1f = %.1f\n", a, b, (float)a + b);
	printf("%.1f - %.1f = %.1f\n", a, b, (float)a - b);
	printf("%.1f * %.1f = %.1f\n", a, b, (float)a * b);
	printf("%.1f / %.1f = %.1f\n", a, b, (float)a / b);

	return 0;
}