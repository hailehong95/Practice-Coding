#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// a.x^4 + b.x^2 + c = 0

int main()
{
	/*
	** Phương pháp đặt ẩn phụ: t = x^2 (t >= 0)
	** => at^2 + bt + c = 0
	** Khi tính ra được một nghiệm t => Có 2 nghiệm x là: +sqrt(t) và -sqrt(t)
	*/
	float a, b, c;

	printf("Giai phuong trinh ax^4 + bx^2 + c = 0\n");
	printf("Nhap cac he so a, b, c = ");
	scanf("%f %f %f", &a, &b, &c);

	if (a == 0) {
		// PT bậc nhất b.x + c = 0
		if (b == 0) {
			if (c == 0) printf("Phuong trinh co vo so nghiem\n");
			else printf("Phuong trinh vo nghiem\n");
		}
		else {
			float t = -c / b;
			if (t < 0) printf("Phuong trinh vo nghiem\n");
			else
			{
				float x1 = sqrt(t);
				float x2 = -sqrt(t);
				printf("X1 = %f\n", x1);
				printf("X2 = %f\n", x2);
			}
		}
	}
	else {
		float delta = b * b - 4 * a * c;
		if (delta > 0) {
			float t1 = (-b - sqrt(delta)) / (2 * a);
			float t2 = (-b + sqrt(delta)) / (2 * a);
			if (t1 >= 0) {
				float x1 = sqrt(t1);
				float x2 = -sqrt(t1);
				printf("X1 = %f\n", x1);
				printf("X2 = %f\n", x2);
			}
			if (t2 >= 0) {
				float x3 = sqrt(t2);
				float x4 = -sqrt(t2);
				printf("X3 = %f\n", x3);
				printf("X4 = %f\n", x4);
			}
			if (t1 < 0 && t2 < 0) {
				printf("Phuong trinh vo nghiem\n");
			}
		}
		else if (delta == 0) {
			float t = -b / (2 * a);
			if (t < 0) printf("Phuong trinh vo nghiem\n");
			else {
				float x1 = sqrt(t);
				float x2 = -sqrt(t);
				printf("X1 = %f\n", x1);
				printf("X2 = %f\n", x2);
			}
		}
		else {
			printf("Phuong trinh vo nghiem\n");
		}
	}

	return 0;
}