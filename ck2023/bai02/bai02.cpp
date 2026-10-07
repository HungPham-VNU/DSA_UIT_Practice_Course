#include <iostream>
#include <string>
using namespace std;

struct HocSinh {
	string MaSo;
	float Toan;
	float Van;
	float Anh;
};

struct Node {
	HocSinh data;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
};

void InputElement(HocSinh& x) {
	getline(cin >> ws, x.MaSo);
	cin >> x.Toan;
	cin >> x.Van;
	cin >> x.Anh;
}

void Output(List p) {
	if (p.head == NULL) return;
	Node* travel = p.head;
	while (travel != NULL) {
		cout << travel->data.MaSo << ' ' << travel->data.Toan << ' ' << travel->data.Van << ' ' << travel->data.Anh << '\n';
		travel = travel->next;
	}
}

void CreateList(List& p) {
	p.head = p.tail = NULL;
}

Node* CreateNode(HocSinh x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void Addtail(List& p, HocSinh x) {
	if (p.head == NULL) 
	{
		p.head = p.tail = CreateNode(x);
	}
	else
	{
		Node* travel = p.head;
		while (travel->next != NULL) travel = travel->next;
		travel->next = CreateNode(x);
	}
}

int main()
{
	List ds;
	CreateList(ds);
	int n; //so hoc sinh
	HocSinh temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		InputElement(temp);
		if (((temp.Toan + temp.Van + temp.Anh) / 3) >= 9.0) Addtail(ds, temp);
	}
	Output(ds);

	return 0;
}