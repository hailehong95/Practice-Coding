#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define basic_salary 7000000

int main()
{
	/*
	** salary (lương) = coefficients_salary (hệ số) * basic_salary (lương cơ bản)
	** basic_salary = 1500000 VNĐ
	** Nếu: KN < 12 tháng => coefficients_salary = 1.92
	** Nếu: 12 <= KN < 36 tháng => coefficients_salary = 2.34
	** Nếu: 36 <= KN < 60 tháng => coefficients_salary = 3
	** Nếu: KN >= 60 tháng => coefficients_salary = 4.5
	*/
	float coefficients_salary;
	unsigned long seniority, salary; // seniority = thâm niên theo tháng

	printf("Your seniority (month) = ");
	scanf("%d", &seniority);

	if (seniority < 12) coefficients_salary = 1.92;
	else if (seniority >= 12 && seniority < 36) coefficients_salary = 2.34;
	else if (seniority >= 36 && seniority < 60) coefficients_salary = 3.0;
	else coefficients_salary = 4.5;

	salary = coefficients_salary * basic_salary;
	printf("Salary = %ld VND\n", salary);

	return 0;
}