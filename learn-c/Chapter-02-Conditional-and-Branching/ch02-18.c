#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DANSOHIENTAI 1000000
#define TLT 1.8

int main()
{
	/*
	** Tỷ lệ tăng sau mỗi năm = 1.8%
	*/
	float Tong = DANSOHIENTAI;
	float TyLe = TLT / 100;
	printf("%f\n", TyLe);
	printf("Dan so nam 2023: %.2f\n", Tong);
	Tong += Tong * TyLe;
	printf("Dan so nam 2024: %.2f\n", Tong);
	Tong += Tong * TyLe;
	printf("Dan so nam 2025: %.2f\n", Tong);
	Tong += Tong * TyLe;
	printf("Dan so nam 2026: %.2f\n", Tong);
	Tong += Tong * TyLe;
	printf("Dan so nam 2027: %.2f\n", Tong);
	Tong += Tong * TyLe;
	printf("Dan so nam 2028: %.2f\n", Tong);

	return 0;
}