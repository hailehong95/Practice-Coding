#include "KiemTraSo.h"

int KiemTraNguyenTo(int n)
{
	if (n < 2)
		return 0;
	else if (n > 2)
	{
		if (n % 2 == 0)
			return 0;
		for (int i = 3; i <= (int)sqrt((double)n); i += 2)
			if (n % i == 0)
				return 0;
	}
	return 1;
}

int KiemTraChinhPhuong(int n)
{
	return sqrt((double)n) == (int)sqrt((double)n);
}