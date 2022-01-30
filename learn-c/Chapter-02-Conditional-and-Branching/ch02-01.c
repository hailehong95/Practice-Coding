#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int min, max;
	int a = 0, b = 0;

	printf("Enter two numbers = ");
	scanf("%d %d", &a, &b);
	if (a > b) {
		max = a;
		min = b;
	}
	else if (a < b) {
		max = b;
		min = a;
	}
	else {
		min = max = a;
	}
	printf("Min = %d\nMax = %d\n", min, max);

	int min_, max_;
	int c = 0, d = 0, e = 0;
	printf("\nEnter three numbers = ");
	scanf("%d %d %d", &c, &d, &e);
	min_ = max_ = c;
	if (d > max_) max_ = d;
	if (d < min_) min_ = d;
	if (e > max_) max_ = e;
	if (e < min_) min_ = e;
	printf("Min = %d\nMax = %d\n", min_, max_);

	return 0;
}