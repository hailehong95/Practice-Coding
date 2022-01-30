#include <stdio.h>

// Hello World!

int main()
{
	char hello[] = "Hello";
	char* world = "World!";
	char formatString[] = "%s %s";

	// printf(formatString, hello, world);
	// calling convention: cdecl
	__asm
	{
		mov eax, world;
		push eax;
		lea eax, hello;
		push eax;
		lea eax, formatString;
		push eax;
		call DWORD ptr printf; /* Hoặc call printf; */
		pop ebx;
		pop ebx;
		pop ebx;
	}

	return 0;
}