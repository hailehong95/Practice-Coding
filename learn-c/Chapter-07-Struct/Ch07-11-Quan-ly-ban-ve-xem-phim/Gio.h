#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Gio
{
	int Hour, Minute, Second;
}GIO;

void NhapGio(GIO &);
void XuatGio(GIO);