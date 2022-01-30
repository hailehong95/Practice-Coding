#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Sum of Arrays

int sumArr(int* arr, int n)
{
	int kq = 0;
	__asm
	{
		mov ebx, arr;
		xor eax, eax;
		mov ecx, n;

	lbSum:
		add eax, [ebx];
		add ebx, 4;
		loop lbSum;
		mov kq, eax;
	}
	return kq;
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	printf("sum = %d", sumArr(arr, 5));

	return 0;
}