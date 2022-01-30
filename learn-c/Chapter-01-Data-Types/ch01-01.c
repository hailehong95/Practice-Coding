#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main()
{
	int yob = 0;
	time_t t = time(NULL);
	struct tm* tm = localtime(&t);

	printf("Enter year of birth: ");
	scanf("%d", &yob);
	printf("Your are %d years old!\n", (tm->tm_year + 1900) - yob);

	return 0;
}