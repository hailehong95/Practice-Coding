#pragma once
#include <string>
#include "SinhVien.h"
#include <conio.h>
#include <windows.h>
using namespace std;

class Process
{
public:
	// Các Phương thức kiểm tra
	bool KiemTraSinhVien(string sobaodanh, int &vitri);
	bool KiemTraSoBaoDanh(string sobaodanh);
	bool KiemTraTongDiem(double tongdiem);
	bool KiemTraDiemToan(double diemtoan);
	bool KiemTraDiemHoa(double diemhoa);
	bool KiemTraDiemLy(double diemly);
	bool KiemTraHoTen(string hoten);

	// Các Phương thức tìm kiếm
	void TimKiemSoBaoDanh(string sobaodanh);
	void TimKiemTongDiem(double tongdiem);
	void TimKiemHoTen(string hoten);
	void TimKiemDiemToan(double diemtoan);
	void TimKiemDiemLy(double diemly);
	void TimKiemDiemHoa(double diemhoa);

	// Các Phương thức Sắp xếp
	void SapXepDiemTong();
	void SapXepSoBaoDanh();
	void SapXepAnphabe();

	// Các Phương thức khác
	void ThemSinhvien(int n);
	void SuaSinhVien(string sobaodanh);
	void XoaSinhVien(string sobaodanh);
	void ThongKeTatCa();
	void XuatSinhVienRaFile(string fileName);
	void NhapSinhVienTuFile(string fileName);

	DWORD WINAPI threadNhap(LPVOID arg);
	string Convert(int i);
	int DemSoFile(string maTruong);
	void SuaSinhVienv2(string sobaodanh);
};