#include <iostream>
#include <string>
using namespace std;

struct SinhVien 
{
	int MSSV;
	string HoTen;
	float DTB;
	void Nhap();
	void Xuat();
};

struct Node 
{
	SinhVien Info;
	Node* NodeLeft;
	Node* NodeRight;
};
typedef Node* Tree;

void InsertNode(Tree&);
void Nhap(Tree&);
void Xuat(Tree);

int main() 
{
	Tree T = NULL;
	Nhap(T);
	Xuat(T);
	cout << '\n';
	cout << T << '\n' << T->NodeLeft << '\n' << T->NodeRight;

	return 0;
}

void SinhVien::Nhap() {
	cout << "Nhap ma so sinh vien: "; 
	cin >> MSSV;
	cout << "Nhap ho ten: "; 
	cin.ignore();
	getline(cin, HoTen);
	cout << "Nhap diem trung binh: ";
	cin >> DTB;
}

void SinhVien::Xuat() {
	cout << "Ma so sinh vien: " << MSSV << ", Ho ten: " << HoTen << ", Diem trung binh: " << DTB << '\n';
}

void Nhap(Tree& T) 
{
	int n = 0;
	cout << "Nhap so sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		InsertNode(T);
	}
}

void InsertNode(Tree& T) {
	Node* NewNode;
	NewNode = new Node;
	NewNode->NodeLeft = NULL;
	NewNode->NodeRight = NULL;
	NewNode->Info.Nhap();
	if (T == NULL)
	{
		T = NewNode;
	}
	else 
	{
		Node* temp = T;
		while (temp != NULL)
		{
			if (temp->Info.DTB == NewNode->Info.DTB) return;
			if (temp->Info.DTB < NewNode->Info.DTB)
				temp = temp->NodeRight;
			else
				temp = temp->NodeLeft;
		}
		temp = NewNode;
		cout << "Insert thanh cong " << temp << '\n';
	}
}

void Xuat(Tree T)
{
	if (T != NULL)
	{
		Xuat(T->NodeLeft);
		T->Info.Xuat();
		Xuat(T->NodeRight);
	}
}