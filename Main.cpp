#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Function.h"
using namespace std;

int main()
{
	SINHVIEN *a;
	int n;
	string file = "DanhSachSinhVien.txt";
	a = new SINHVIEN[200];
	Nhap(a, n, file);
	Menu(a, n, file);
	delete[] a;
	return 0;
}
