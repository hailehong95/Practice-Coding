#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 0, b = 0;
	
	printf("enter two numbers = ");
	scanf("%d %d", &a, &b);
	
	int min = a < b ? a : b;
	int max = a > b ? a : b;
	printf("Min = %d\nMax = %d\n", min, max);
	
	
	int c = 0, d = 0, e = 0;
	
	printf("enter three numbers = ");
	scanf("%d %d %d", &c, &d, &e);
	
	int min_ = c < d ? c : d;
	min_ = min_ < e ? min_ : e;
	int max_ = c > d ? c : d;
	max_ = max_ > e ? max_ : e;
	printf("Min = %d\nMax = %d\n", min_, max_);
	
	return 0;
}