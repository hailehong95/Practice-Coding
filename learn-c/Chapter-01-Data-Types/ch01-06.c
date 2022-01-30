#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
input_:
	int license_plate = 0;

	printf("License plate = ");
	scanf("%d", &license_plate);

	int count_number = log10((double)license_plate) + 1;
	if (count_number != 5)
		goto input_;

	int sum = 0;
sum_calc:
	sum += license_plate % 10;
	license_plate /= 10;
	if (license_plate != 0)
		goto sum_calc;

	printf("Sum = %d\n", sum);

	return 0;
}