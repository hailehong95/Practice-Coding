#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define TOM		0
#define CUA		1
#define BAU		2
#define GA		3
#define CA		4
#define HUOU	5
unsigned long SoTienHienTai = 100;

// Người chơi đặt cược và đợi thông báo

int main()
{
	char key;
	unsigned long TienTom, TienCua, TienBau, TienGa, TienCa, TienHuou;
	do
	{
		int DanhSachDat[6] = { 0 };
		system("cls");
		printf("So Tien hien tai: %d\n", SoTienHienTai);
		do
		{
			printf("Dat Cuoc (Tom|Cua|Bau|Ga|Ca|Huou): ");
			scanf("%d %d %d %d %d %d", &TienTom, &TienCua, &TienBau, &TienGa, &TienCa, &TienHuou);
			DanhSachDat[TOM] = TienTom;
			DanhSachDat[CUA] = TienCua;
			DanhSachDat[BAU] = TienBau;
			DanhSachDat[GA] = TienGa;
			DanhSachDat[CA] = TienCa;
			DanhSachDat[HUOU] = TienHuou;

			if ((TienTom + TienCua + TienBau + TienGa + TienCa + TienHuou) > SoTienHienTai)
				printf("So tien hien tai khong du\n");
		} while ((TienTom + TienCua + TienBau + TienGa + TienCa + TienHuou) > SoTienHienTai);

		printf("Dang quay so ");
		for (int i = 0; i < 2; i++) {
			Sleep(700);
			printf(" .");
		}
		printf(" .\n");

		printf("Ket qua: ");
		// Quay số ngẫu nhiên từ [1, 6]
		srand(time(0));
		Sleep(1000);
		int Lan1[6] = { 0 };
		int kq1 = 0 + rand() % (5 - 0 + 1);
		Lan1[kq1] = 1;
		if (kq1 == TOM) printf("TOM, ");
		if (kq1 == CUA) printf("CUA, ");
		if (kq1 == BAU) printf("BAU, ");
		if (kq1 == GA) printf("GA, ");
		if (kq1 == CA) printf("CA, ");
		if (kq1 == HUOU) printf("HUOU, ");

		srand(time(0));
		Sleep(1000);
		int Lan2[6] = { 0 };
		int kq2 = 0 + rand() % (5 - 0 + 1);
		Lan2[kq2] = 1;
		if (kq2 == TOM) printf("TOM, ");
		if (kq2 == CUA) printf("CUA, ");
		if (kq2 == BAU) printf("BAU, ");
		if (kq2 == GA) printf("GA, ");
		if (kq2 == CA) printf("CA, ");
		if (kq2 == HUOU) printf("HUOU, ");

		srand(time(0));
		Sleep(1000);
		int Lan3[6] = { 0 };
		int kq3 = 0 + rand() % (5 - 0 + 1);
		Lan3[kq3] = 1;
		if (kq3 == TOM) printf("TOM\n");
		if (kq3 == CUA) printf("CUA\n");
		if (kq3 == BAU) printf("BAU\n");
		if (kq3 == GA) printf("GA\n");
		if (kq3 == CA) printf("CA\n");
		if (kq3 == HUOU) printf("HUOU\n");

		printf("Dang tinh lai tien ");
		for (int i = 0; i < 2; i++) {
			Sleep(700);
			printf(" .");
		}
		printf(" .\n");

		for (int i = 0; i < 6; i++) {
			int count = 0;
			if (DanhSachDat[i] > 0) {
				if (Lan1[i] == 1) count += 1;
				if (Lan2[i] == 1) count += 1;
				if (Lan3[i] == 1) count += 1;
				if (count > 0) {
					SoTienHienTai += DanhSachDat[i] * count;
				}
				else {
					SoTienHienTai -= DanhSachDat[i];
				}
			}
		}

		// Kết quả tính tiền
		printf("So Tien hien tai: %d\n", SoTienHienTai);

		// Thông báo hết tiền
		if (SoTienHienTai <= 0) {
			char naptiep;
			rewind(stdin);
			printf("Ban da het tien. Ban co muon nap tien khong (y/n)? ");
			scanf("%c", &naptiep);
			if (naptiep == 'y') {
				unsigned long SoTienNap;
				printf("Nhap so tien muon nap: ");
				scanf("%d", &SoTienNap);
				SoTienHienTai += SoTienNap;
				printf("Da nap %ld\n", SoTienNap);
			}
			else {
				printf("Ban khong con tien de choi. Chuong trinh se ket thuc!");
				break;
			}
		}
		rewind(stdin);
		printf("Ban co muon choi tiep (y/n)? ");
		scanf("%c", &key);

	} while (key == 'y');

	return 0;
}