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
void Print_List(List&);
void Delete_List(List&);

int main()
{
	List A;
	Create_List(A);
	Print_List(A);
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

void Print_List(List& p) {
	Node* temp = p.head;
	while (temp != NULL) {
		cout << temp->Data << ' ';
		temp = temp->next;
	}
}

void Delete_List(List& p) {
	Node* temp = p.head;
	while (temp != NULL) {
		p.head = p.head->next;
		delete temp;
		temp = p.head;
	}
}