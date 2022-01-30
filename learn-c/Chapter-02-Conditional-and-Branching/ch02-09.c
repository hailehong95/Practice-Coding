#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int month, year;
	printf("Enter month and year = ");
	scanf("%d%d", &month, &year);

	if (month < 1 || month > 12) {
		printf("Invalid input month!\n");
		return 1;
	}
	if (year < 1940) {
		printf("Invalid input year!\n");
		return 2;
	}

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		printf("%d/%d have 31 days\n", month, year);
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		printf("%d/%d have 30 days\n", month, year);
	else {
		/*
		** Năm nhuận là năm thỏa mãn:
		** - Chia hết cho 4 và không chia hết cho 100: year % 4 == 0 && year % 100 != 0
		** - Chia hết cho 400: year % 400 == 0
		*/
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			printf("%d/%d have 29 days (leap year)\n", month, year);
		else
			printf("%d/%d have 28 days\n", month, year);
	}

	return 0;
}