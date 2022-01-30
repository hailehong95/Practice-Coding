#include <stdio.h>

// Function

int sum(int x, int y)
{
	__asm
	{
		mov eax, x;
		mov ebx, y;
		add eax, ebx;
		mov x, eax;
	}
	return x;
}

int main()
{
	// sum function
	int result = sum(6, 9);
	printf("sum = %d\n", result);

	return 0;
}