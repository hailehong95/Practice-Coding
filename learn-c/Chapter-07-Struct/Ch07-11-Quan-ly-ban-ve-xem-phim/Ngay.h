#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Ngay
{
	int Day, Month, Year;
}NGAY;

void NhapNgay(NGAY &);
void XuatNgay(NGAY);