#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Giai thua (Factorial)

int sumS(int n)
{

	int kq = 0;
	__asm
	{
		xor eax, eax;
		mov ecx, n;
		xor ebx, ebx;
		add ebx, 1;

	lbSum:
		add eax, ebx;
		inc ebx;
		loop lbSum;
		mov kq, eax;
	}
	return kq;
}

int TinhGiaiThua(int n)
{
	int kq = 0;
	__asm
	{
		xor eax, eax;
		mov eax, 1;
		mov ecx, n;
		xor ebx, ebx;
		mov ebx, n;

	lbGiaiThua:
		mul ebx; // eax = eax * ebx
		dec ebx;
		loop lbGiaiThua;
		mov kq, eax;
	}

	return kq;
}

int TongGiaiThua(int n)
{
	int kq = 0;
	__asm
	{
		xor eax, eax;
		xor ebx, ebx;
		mov ebx, 1;
	lb_TongGiaiThua:
		push ebx;
		call TinhGiaiThua; // TinhGiaiThua(ebx)
		add kq, eax;
		pop edx; // clean stack
		inc ebx;
		cmp ebx, n;
		jg _exit;
		jmp lb_TongGiaiThua;
	_exit:

	}

	return kq;
}


int main()
{
#if 0
	// Tổng S = 1 + 2 + 3 + .. + n. Với n nhập từ bàn phím
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);

	printf("Sum S = %d", sumS(n));
#endif // 1

#if 0
	// n!. VD: 3! = 3*2*1 = 6; 5! = 5*4*3*2*1 = 120
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("%d! = %d", n, TinhGiaiThua(n));
#endif // 1

#if 1
	// Tính tổng: 1! + 2! + 3! + 4! + .. + n!. Với n nhập từ bàn phím
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("Tong cac giai thua = %d", TongGiaiThua(n));
#endif // 1

	return 0;
}