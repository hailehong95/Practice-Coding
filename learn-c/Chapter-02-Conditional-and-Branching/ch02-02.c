#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ax + b = 0

int main()
{
	int a = 0, b = 0;
	printf("Nhap a, b = ");
	scanf("%d %d", &a, &b);

	if (a == 0) {
		if (b == 0) printf("Vo so nghiem\n");
		else printf("Vo nghiem\n");
	}
	else {
		printf("x = %.3f\n", (float)-b / a);
	}

	return 0;
}