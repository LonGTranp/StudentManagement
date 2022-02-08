#include <iostream>
#include "Function.h"
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

void Nhap(SINHVIEN &a, ifstream &FileIn)
{
	FileIn.ignore();
	getline(FileIn, a.ten);
	FileIn >> a.tuoi;
	FileIn >> a.diem;
}

void Nhap(SINHVIEN a[], int &n, string fileName)
{
	ifstream FileIn;
	FileIn.open(fileName);
	FileIn >> n;
	for (int i = 0; i < n; i++)
	{
		Nhap(a[i], FileIn);
	}
	FileIn.close();
}

void Xuat(SINHVIEN a, int k)
{
	cout << setw(10) << right << "| " << k;
	cout << "    | " << setw(20) << left << a.ten;
	cout << "| " << setw(9) << a.tuoi << "| ";
	cout << setw(7) << a.diem << "|" << endl;
}

void Xuat(SINHVIEN a[], int n)
{
	cout << setw(59) << right << "+------+---------------------+----------+--------+\n";
	cout << setw(59) << "| STT  | Ho va ten           | Tuoi     | Diem   |\n";
	cout << setw(59) << "+------+---------------------+----------+--------+\n";
	for (int i = 0; i < n; i++)
	{
		Xuat(a[i], i + 1);
	}
	cout << setw(59) << right << "+------+---------------------+----------+--------|\n";
}

void Menu(SINHVIEN a[], int n, string fileName)
{
	int input;
	bool on_off = true;
	while (on_off)
	{
		MenuInfor();
		cout << "\nNhap thao tac: ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "[1] In danh sach sinh vien: \n";
			Xuat(a, n);
			break;
		case 2:
			cout << "[2] Them sinh vien: \n";
			ThemSV(a, n);
			Xuat(a, n);
			break;
		case 3:
			cout << "[3] Xoa sinh vien: \n";
			Xuat(a, n);
			XoaSV(a, n);
			Xuat(a, n);
			cout << "Da xoa thanh cong.\n";
			break;
		case 4:
			cout << "[4] Sua thong tin sinh vien: \n";
			Xuat(a, n);
			SuaSV(a, n);
			Xuat(a, n);
			cout << "Da sua thanh cong.\n";
			break;
		case 5:
			cout << "[5] Thong ke thong tin sinh vien: \n";
			ThongKe(a, n);
			break;
		case 6:
			cout << "[6] Sap xep thong tin sinh vien: \n";
			SapXep(a, n);
			break;
		case 7:
			system("cls");
			break;
		case 8:
			cout << "[8] Tro lai danh sach ban dau: \n";
			Nhap(a, n, fileName);
			Xuat(a, n);
			cout << "Da tro lai thanh cong.\n";
			break;
		case 9:
			cout << "[9] Luu lai danh sach sinh vien: \n";
			cout << "...\nDa luu lai thanh cong.\n";
			SaveFile(a, n, fileName);
			break;
		case 10:
			on_off = false;
			break;
		}
	}
}

void MenuInfor()
{
	cout << "\n***************MENU***************\n";
	cout << "|1 - In danh sach sinh vien      |\n";
	cout << "|2 - Them mot sinh vien          |\n";
	cout << "|3 - Xoa mot sinh vien           |\n";
	cout << "|4 - Sua thong tin sinh vien     |\n";
	cout << "|5 - Thong ke thong tin sinh vien|\n";
	cout << "|6 - Sap xep thong tin sinh vien |\n";
	cout << "|7 - Xoa man hinh hien tai       |\n";
	cout << "|8 - Tro lai danh sach ban dau   |\n";
	cout << "|9 - Luu lai danh sach sinh vien |\n";
	cout << "|10 - Thoat                      |\n";
	cout << "**********************************\n";
}

void ThemSV(SINHVIEN a[], int &n)
{
	cout << "Nhap ten cua sinh vien can them: ";
	cin.ignore();
	getline(cin, a[n].ten);
	cout << "Nhap tuoi cua sinh vien can them: ";
	cin >> a[n].tuoi;
	cout << "Nhap diem cua sinh vien can them: ";
	cin >> a[n].diem;
	cout << "Da them sinh vien: " << a[n].ten << ", " << a[n].tuoi << " tuoi.\n";
	n++;
}

void XoaSV(SINHVIEN a[], int &n)
{
	int k;
	cout << "Nhap so thu tu cua sinh vien can xoa: ";
	cin >> k;
	for (int i = k - 1; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

void SuaSV(SINHVIEN a[], int n)
{
	int k, c;
	cout << "Nhap so thu tu cua sinh vien can sua: ";
	cin >> k;
	cout << "1. Sua ten\n";
	cout << "2. Sua tuoi\n";
	cout << "3. Sua diem\n";
	cout << "Nhap thao tac: ";
	cin >> c;
	switch (c)
	{
	case 1:
		cout << "Nhap ten moi: ";
		cin.ignore();
		getline(cin, a[k - 1].ten);
		break;
	case 2:
		cout << "Nhap tuoi moi: ";
		cin >> a[k - 1].tuoi;
		break;
	case 3:
		cout << "Nhap diem moi: ";
		cin >> a[k - 1].diem;
		break;
	default:
		break;
	}
}

void SaveFile(SINHVIEN a[], int n, string fileName)
{
	ofstream FileOut;
	FileOut.open(fileName);
	FileOut << n;
	for (int i = 0; i < n; i++)
	{
		FileOut << endl
				<< a[i].ten << endl
				<< a[i].tuoi << endl
				<< a[i].diem;
	}
	FileOut.close();
}

void ThongKe(SINHVIEN a[], int n)
{
	ThongKeNam(a, n);
	XepLoai(a, n);
}

void XepLoai(SINHVIEN a[], int n)
{
	float demGioi = 0;
	float demKha = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].diem > 8)
			demGioi++;
		else if (a[i].diem > 5)
			demKha++;
	}
	float demTB = n - demGioi - demKha;
	float phanTramGioi = (double)(demGioi / n) * 100.0;
	float phanTramKha = (double)(demKha / n) * 100.0;
	float phanTramTB = (double)(demTB / n) * 100.0;

	cout << setprecision(4) << "\n- Co " << phanTramGioi << "% sinh vien loai gioi.\n";
	cout << setprecision(4) << "- Co " << phanTramKha << "% sinh vien loai kha.\n";
	cout << setprecision(4) << "- Co " << phanTramTB << "% sinh vien loai trung binh.\n";
	cout << "--------------------------------------\n";
}

void ThongKeNam(SINHVIEN a[], int n)
{
	int demNam1 = 0;
	int demNam2 = 0;
	int demNam3 = 0;
	for (int i = 0; i < n; i++)
	{
		switch (a[i].tuoi)
		{
		case 18:
			demNam1++;
			break;
		case 19:
			demNam2++;
			break;
		case 20:
			demNam3++;
			break;
		default:
			break;
		}
	}
	int demNam4 = n - demNam1 - demNam2 - demNam3;
	cout << "\n--------------------------------------";
	cout << "\n- Co " << demNam1 << " sinh vien nam 1.\n";
	cout << "- Co " << demNam2 << " sinh vien nam 2.\n";
	cout << "- Co " << demNam3 << " sinh vien nam 3.\n";
	cout << "- Co " << demNam4 << " sinh vien nam 4.\n";
	cout << "--------------------------------------";
}

void SapXep(SINHVIEN a[], int n)
{
	int input, input2;
	cout << "1. Sap xep theo ten\n";
	cout << "2. Sap xep theo tuoi\n";
	cout << "3. Sap xep theo diem\n";
	cout << "Nhap thao tac: ";
	cin >> input;
	cout << "\n1. Sap xep tang dan\n";
	cout << "2. Sap xep giam dan\n";
	cout << "Nhap thao tac: ";
	cin >> input2;

	switch (input)
	{
	case 1:
		SapXepTen(a, n, input2);
		Xuat(a, n);
		break;
	case 2:
		SapXepTuoi(a, n, input2);
		Xuat(a, n);
		if (input2 == 1)
			cout << "\nDa sap xep theo tuoi tang dan thanh cong.\n";
		else
			cout << "\nDa sap xep theo tuoi giam dan thanh cong.\n";
		break;
	case 3:
		SapXepDiem(a, n, input2);
		Xuat(a, n);
		if (input2 == 1)
			cout << "\nDa sap xep theo diem tang dan thanh cong.\n";
		else
			cout << "\nDa sap xep theo diem giam dan thanh cong.\n";
		break;
		break;
	default:
		break;
	}
}

void SapXepTen(SINHVIEN a[], int n, int k)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(a[i].ten.c_str(), a[j].ten.c_str()) > 0)
				HoanVi(a[i], a[j]);
		}
	}
}

void SapXepTuoi(SINHVIEN a[], int n, int k)
{
	switch (k)
	{
	case 1:
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i].tuoi > a[j].tuoi)
					HoanVi(a[i], a[j]);
			}
		}
		break;
	case 2:
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i].tuoi < a[j].tuoi)
					HoanVi(a[i], a[j]);
			}
		}
		break;
	default:
		break;
	}
}

void SapXepDiem(SINHVIEN a[], int n, int k)
{
	switch (k)
	{
	case 1:
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i].diem > a[j].diem)
					HoanVi(a[i], a[j]);
			}
		}
		break;
	case 2:
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i].diem < a[j].diem)
					HoanVi(a[i], a[j]);
			}
		}
		break;
	default:
		break;
	}
}

void HoanVi(SINHVIEN &a, SINHVIEN &b)
{
	SINHVIEN temp = a;
	a = b;
	b = temp;
}