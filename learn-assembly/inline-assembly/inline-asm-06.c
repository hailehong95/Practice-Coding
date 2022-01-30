#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Prime

int isPrime(int x)
{
	int kq = 0; // false
	__asm
	{
		xor eax, eax;
		mov eax, x;
		cmp eax, 2;
		jl lbfalse;
		je lbtrue;
		jg xGreat2;
		jmp endGame;

	xGreat2:
		cmp eax, 3;
		je lbtrue;
		xor edx, edx;
		mov ecx, 2;
		div ecx;
		cmp edx, 0; // x % 2 == 0 => false
		je lbfalse;

		mov ecx, eax; // counter = x / 2
		mov ebx, 3; // int i = 3
		jmp lbloop;

	lbloop:
		xor edx, edx;
		xor eax, eax;
		mov eax, x;
		div ebx;
		cmp edx, 0;
		je lbfalse;
		add ebx, 2;
		cmp ebx, ecx;
		jle lbloop;
		jmp lbtrue;

	lbfalse:
		mov kq, 0;
		jmp endGame;

	lbtrue:
		mov kq, 1;
	endGame:
		nop;
	}
	return kq;
}

void showPrime(int n)
{
	char formatstr[] = "%d   ";
	__asm
	{
		mov ebx, 1;
	lbloop:
		cmp ebx, n;
		jg endGame;

		push ebx;
		call isPrime;
		pop edx;
		cmp eax, 1;
		je __printf;
		inc ebx;
		jmp lbloop;

	__printf:
		push ebx;
		lea eax, formatstr;
		push eax;
		call DWORD ptr printf;
		pop edx;
		pop edx;
		inc ebx;
		jmp lbloop;

	endGame:
		nop;
	}
}

int main()
{
	// in ra các số nguyên tố  < n
	showPrime(100);

	return 0;
}