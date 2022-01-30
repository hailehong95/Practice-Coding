#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int number, flag = 0;
	printf("Nhap so co 3 chu so: ");
	scanf("%d", &number);

	// detect negative number
	if (number < 0)
	{
		flag = 1;
		number *= -1;
	}

	int count_num = log10((double)number) + 1;

	if (count_num != 3) printf("So khong hop le!\n");
	else
	{
		// 123 / 10 = 12 % 10 = 2
		int dv = number % 10;
		int ch = (number / 10) % 10;
		int tr = number / 100;

		if (flag == 1) printf("Am ");

		if (tr == 1) printf("Mot ");
		if (tr == 2) printf("Hai ");
		if (tr == 3) printf("Ba ");
		if (tr == 4) printf("Bon ");
		if (tr == 5) printf("Nam ");
		if (tr == 6) printf("Sau ");
		if (tr == 7) printf("Bay ");
		if (tr == 8) printf("Tam ");
		if (tr == 9) printf("Chin ");

		printf("tram ");

		if (ch == 0 && dv != 0) printf("Le ");

		//if (ch == 1) printf("Muoi ");
		if (ch == 2) printf("Hai ");
		if (ch == 3) printf("Ba ");
		if (ch == 4) printf("Bon ");
		if (ch == 5) printf("Nam ");
		if (ch == 6) printf("Sau ");
		if (ch == 7) printf("Bay ");
		if (ch == 8) printf("Tam ");
		if (ch == 9) printf("Chin ");

		if (ch != 0) printf("Muoi ");

		if (dv == 1) printf("Mot");
		if (dv == 2) printf("Hai");
		if (dv == 3) printf("Ba");
		if (dv == 4) printf("Bon");
		if (dv == 5) printf("Nam");
		if (dv == 6) printf("Sau");
		if (dv == 7) printf("Bay");
		if (dv == 8) printf("Tam");
		if (dv == 9) printf("Chin");
	}

	return 0;
}