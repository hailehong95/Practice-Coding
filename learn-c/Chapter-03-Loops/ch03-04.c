#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	/*
	** VD số chính phương: 0, 1, 4, 9, 16, 25, 36...
	** => Số chính phương là số mà đem khai căn b2 thì kết quả là một số nguyên
	*/

	int n;
choice:
	do
	{
		printf("Nhap n (n > 0): ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Nhap lai n\n");
	} while (n <= 0);

	if (sqrt((float)n) == (int)sqrt((float)n))
		printf("So %d la so chinh phuong\n", n);
	else
		printf("So %d khong phai so chinh phuong\n", n);

	printf("Ban co muon nhap tiep (y/n)? ");
	rewind(stdin);
	char key = getchar();
	if (key == 'y' || key == 'Y')
		goto choice;

	return 0;
}