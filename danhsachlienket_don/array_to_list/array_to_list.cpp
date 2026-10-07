#include <iostream>

struct Node {
	int Data;
	Node* Next;
};

struct List {
	Node* head;
	Node* tail;
};


void Create_List(List&);
void Add_List(List&, int);
void Print_List(List&);
void Destruction(List&);
void Search(List, int);
void Add_head(List&, int);


int main()
{
	List I;
	Create_List(I);
	Add_List(I, 5);
	Add_List(I, 6);
	Add_List(I, 7);
	Print_List(I);
//	Search(I, 6);
	Add_head(I, 1);
	Print_List(I);
	Destruction(I);
	return 0;
}

void Create_List(List& p) {
	p.head = NULL;
	p.tail = NULL;
}

void Add_List(List& p, int x) {
	Node* newNode = new Node;
	newNode->Data = x;
	newNode->Next = NULL;

	if (p.head == NULL) p.head = newNode;
	else {
		Node* temp = p.head;
		while (temp->Next != NULL) {
			temp = temp->Next;
		}
		temp->Next = newNode;
	}
}

void Print_List(List& p) {
	Node* temp = p.head;
	while (temp != NULL) {
		std::cout << temp->Data << ' ';
		std::cout << temp->Next << ' ' << '\n';
		temp = temp->Next;
	}
	std::cout << '\n';
}

void Search(List p, int x) {
	Node* temp = p.head;
	while (temp != NULL && temp->Data != x) {
		temp = temp->Next;
	}
	std::cout << temp;
}

void Add_head(List& I, int x) {
	Node* newNode = new Node;
	newNode->Data = x;
	newNode->Next = NULL;
	if (I.head == NULL) I.head = newNode;
	else {
		newNode->Next = I.head;
		I.head = newNode;
	}
}

void Destruction(List& p){
	Node* temp = p.head;
	while (p.head != NULL) {
		temp = p.head;
		p.head = p.head->Next;
		delete temp;
	}
}
