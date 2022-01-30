#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float dongia;
	unsigned int soluong;

	printf("So luong = ");
	scanf("%d", &soluong);

	printf("Don gia = ");
	scanf("%f", &dongia);

	float sum = (float)soluong * dongia;
	float gtgt = sum * 0.1;

	printf("Tong tien = %.2f\n", sum);
	printf("GTGT = %.2f\n", gtgt);

	return 0;
}