#include <string> 
using namespace std;

struct sinhvien
{
	string ten;
	int tuoi{};
	float diem;
};
typedef struct sinhvien SINHVIEN;

void Nhap(SINHVIEN&, ifstream&);

void Nhap(SINHVIEN[], int&, string);

void Xuat(SINHVIEN, int);

void Xuat(SINHVIEN[], int);

void Menu(SINHVIEN[], int, string);

void MenuInfor();

void ThemSV(SINHVIEN[], int&);

void XoaSV(SINHVIEN[], int&);

void SuaSV(SINHVIEN[], int);

void SaveFile(SINHVIEN[], int, string);

void ThongKe(SINHVIEN[], int);

void XepLoai(SINHVIEN[], int);

void ThongKeNam(SINHVIEN[], int);

void SapXep(SINHVIEN[], int);

void SapXepTen(SINHVIEN[], int, int);

void SapXepTuoi(SINHVIEN[], int, int);

void SapXepDiem(SINHVIEN[], int, int);

void HoanVi(SINHVIEN&, SINHVIEN&);