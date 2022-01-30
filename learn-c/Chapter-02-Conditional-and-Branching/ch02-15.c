#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	/*
	** Số chính phương là số mà đem khai căn b2 thì được kết quả là một số nguyên.
	** VD: 1, 4, 9, 16, 25
	*/

	int n;
	printf("Nhap vao so can kiem tra: ");
	scanf("%d", &n);

#if 0 // Cách 1
	if (sqrt((float)n) == (int)sqrt((float)n))
		printf("La so chinh phuong\n");
	else
		printf("Khong la so chinh phuong\n");
#endif

#if 1 // Cách 2
	if (sqrt((float)n) * sqrt((float)n) == n)
		printf("La so chinh phuong\n");
	else
		printf("Khong la so chinh phuong\n");
#endif

	return 0;
}