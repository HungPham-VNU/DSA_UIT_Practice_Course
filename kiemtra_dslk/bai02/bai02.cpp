#include <iostream>
using namespace std;

struct Node {
	int Data;
	Node* next;
};

struct List {
	Node* head;
};

void Create_List(List&);
void Print_Prime(List&);
void Delete_List(List&);
int check_Prime(int);

int main()
{
	List A;
	Create_List(A);
	Print_Prime(A);
	Delete_List(A);
	return 0;
}

void Create_List(List& p) {
	p.head = NULL;
	int x = 0;
	while (1) {
		cin >> x; if (x == -1) break;
		Node* newNode = new Node;
		newNode->Data = x;
		newNode->next = NULL;
		if (p.head == NULL) p.head = newNode;
		else {
			Node* temp = p.head;
			while (temp->next != NULL) temp = temp->next;
			temp->next = newNode;
		}


	}
}

void Print_Prime(List& p) {
	int check = 0;
	Node* temp = p.head;
	while (temp != NULL) {
		if (check_Prime(temp->Data)) {
			cout << temp->Data << ' ';
			check = 1;
		}
		temp = temp->next;
	}
	if (check == 0) cout << 0;
}

void Delete_List(List& p) {
	Node* temp = p.head;
	while (temp != NULL) {
		p.head = p.head->next;
		delete temp;
		temp = p.head;
	}
}

int check_Prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}