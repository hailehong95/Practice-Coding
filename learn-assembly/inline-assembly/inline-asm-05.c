#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Min-Max

int _Max(int a, int b, int c)
{
	int _max;
	__asm
	{
		xor eax, eax;
		xor ebx, ebx;
		xor ecx, ecx;
		mov eax, a;
		mov ebx, b;
		mov ecx, c;
		cmp eax, ebx; // a vs b
		jg aGreatb;
		jmp bGreata;

	aGreatb:
		cmp eax, ecx; // a vs c
		jg aMax;
		jmp cMax;

	bGreata:
		cmp ebx, ecx; // c vs b
		jg bMax;
		jmp cMax;

	aMax:
		mov _max, eax;
		jmp endGame;

	bMax:
		mov _max, ebx;
		jmp endGame;

	cMax:
		mov _max, ecx;

	endGame:
		nop;
	}
	return _max;
}

int _Min(int a, int b, int c)
{
	int _min;
	__asm
	{
		xor eax, eax;
		xor ebx, ebx;
		mov eax, a;
		mov ebx, b;
		mov ecx, c;
		cmp eax, ebx;
		jl aLessb;
		jmp bLessa;

	aLessb:
		cmp eax, ecx;
		jl aMin;
		jmp cMin;

	bLessa:
		cmp ebx, ecx;
		jl bMin;
		jmp cMin;

	aMin:
		mov _min, eax;
		jmp endGame;

	bMin:
		mov _min, ebx;
		jmp endGame;

	cMin:
		mov _min, ecx;

	endGame:
		nop;
	}
	return _min;
}

int main()
{
	int max = _Max(6, 9, 96);
	int min = _Min(7, 10, 1);
	printf("%d\n", max);
	printf("%d\n", min);

	return 0;
}