#include <iostream>
#include <string>
using namespace std;

struct Sinhvien {
	int Masinhvien;
	string Hoten;
	int Namsinh;	
	int Gioitinh;
	float Diemtrungbinh;
};
Sinhvien a[100];
int n;

void Input();
void Sapxep_maso();
void Sapxep_dtb();
void Output();

int main()
{
	Input();
	Sapxep_maso();
	Sapxep_dtb();
	Output();
}

void Input() {
	cout << "Nhap so sinh vien: "; cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Nhap du lieu cho sinh vien thu " << i << ':' << '\n';
		cout << "Nhap ma sinh vien: "; cin >> a[i].Masinhvien;
		cout << "Nhap ho ten: "; cin >> a[i].Hoten;
		cout << "Nhap nam sinh: "; cin >> a[i].Namsinh;
		cout << "Nhap gioi tinh: "; cin >> a[i].Gioitinh;
		cout << "Nhap diem trung binh: "; cin >> a[i].Diemtrungbinh;
	}
}

void Sapxep_maso() {
	for (int i = 1; i <= n; i++) {
		int min = i;
		for (int j = i; j <= n; j++) {
			if (a[i].Masinhvien > a[j].Masinhvien) min = j;
		}
		if (min != i) swap(a[i], a[min]);
	}
}

void Sapxep_dtb() {
	for (int i = 1; i <= n; i++) {
		int max = i;
		for (int j = i; j <= n; j++) {
			if (a[i].Diemtrungbinh < a[j].Diemtrungbinh) max = j;
		}
		if (max != i) swap(a[i], a[max]);
	}
}

void Output() {
	for (int i = 1; i <= n; i++) {
		cout << "Sinh vien thu " << i << " co thong tin la: ";
		cout << a[i].Masinhvien << '\n';
		cout << a[i].Hoten << '\n';
		cout << a[i].Namsinh << '\n';
		cout << a[i].Gioitinh << '\n';
		cout << a[i].Diemtrungbinh << '\n';
	}
}