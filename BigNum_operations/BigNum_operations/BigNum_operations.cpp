#include <iostream>
#include <string>
using std::string;
string a, b;

struct Node {
	int Data;
	Node* Next;
};

struct List {
	Node* head;
	Node* tail;
};

void Input_num(string&, string&);
List Num_to_list(string, int&);
void Create_List(List&);
void Add_head(List&, int);
void Print_List(List);
void Add_tail(List&, int);
List Num_to_list_reverse(string, int&);
List Add_num(List, List, int, int);
List Minor_num(List, List, int, int);



int main()
{
	Input_num(a, b);
	int num_a = 0, num_b = 0;
	List list_a = Num_to_list_reverse(a, num_a);
	List list_b = Num_to_list_reverse(b, num_b);
	//	Print_List(list_a);
	//	Print_List(list_b);
	List res = Add_num(list_a, list_b, num_a, num_b);
	std::cout << "Ket qua phep cong la: "; Print_List(res);
	res = Minor_num(list_a, list_b, num_a, num_b);
	std::cout << "Ket qua phep tru la: "; Print_List(res);
	return 0;
}

void Input_num(string& x, string& y) {
	std::cout << "Nhap so thu nhat: ";
	getline(std::cin, x);
	std::cout << "Nhap so thu hai: ";
	getline(std::cin, y);
	std::cout << '\n';
}

List Num_to_list(string num, int& count) {
	List res;
	Create_List(res);
	int n = num.size() - 1;
	count = num.size();
	while (n >= 0) {
		int k = (num[n] - '0');
		Add_head(res, k);
		n--;
	}
	return res;
}

void Create_List(List& newList) {
	newList.head = NULL;
	newList.tail = NULL;
}

void Add_head(List& p, int value) {
	Node* newNode = new Node;
	newNode->Data = value;
	newNode->Next = NULL;
	if (p.head == NULL) {
		p.head = newNode; p.tail = p.head;
	}
	else {
		newNode->Next = p.head;
		p.head = newNode;
	}
}

void Print_List(List p) {
	Node* temp = p.head;
	int k = 0;
	while (temp != NULL) {
		if (temp->Data != 0) k = 1;
		if (k == 1) std::cout << temp->Data;
		temp = temp->Next;
	}
	std::cout << '\n';
}

void Add_tail(List& p, int value) {
	Node* newNode = new Node;
	newNode->Data = value;
	newNode->Next = NULL;
	if (p.tail == NULL) {
		p.tail = newNode; p.head = p.tail;
	}
	else {
		p.tail->Next = newNode;
		p.tail = newNode;
	}
}

List Num_to_list_reverse(string num, int& count) {
	List res;
	Create_List(res);
	int n = num.size() - 1;
	count = num.size();
	while (n >= 0) {
		int k = (num[n] - '0');
		Add_tail(res, k);
		n--;
	}
	return res;
}

//function cong hai so nguyen lon, ket qua la mot so nguyen lon luu vao linked list res.
List Add_num(List p, List q, int num_p, int num_q) {
	List res;
	Create_List(res);
	Node* tp = p.head;
	Node* tq = q.head;
	if (num_p < num_q) {
		for (int i = 1; i <= num_q - num_p; i++) Add_tail(p, 0);
	}
	if (num_p > num_q) {
		for (int i = 1; i <= num_p - num_q; i++) Add_tail(q, 0);
	}
	int don_vi = 0;
	while (tp != NULL || tq != NULL) {
		int value = tp->Data + tq->Data + don_vi;
		if (value >= 10) { value -= 10; don_vi = 1; }
		else don_vi = 0;
		Add_head(res, value);
		tp = tp->Next; tq = tq->Next;
		if (tp == NULL && tq == NULL && don_vi == 1) Add_head(res, don_vi);
	}
	return res;
}

//function tru hai so nguyen lon
List Minor_num(List p, List q, int num_p, int num_q) {
	List res, res2;
	Create_List(res);
	Create_List(res2);
	Node* tp = p.head;
	Node* tq = q.head;
	if (num_p < num_q) {
		for (int i = 1; i <= num_q - num_p; i++) Add_tail(p, 0);
	}
	if (num_p > num_q) {
		for (int i = 1; i <= num_p - num_q; i++) Add_tail(q, 0);
	}
	int don_vi = 0;
	while (tp != NULL || tq != NULL) {
		int value = tp->Data - tq->Data - don_vi;
		if (value < 0) {
			value = tp->Data + 10 - tq->Data - don_vi;
			don_vi = 1;
		}
		else don_vi = 0;
		Add_head(res, value);
		tp = tp->Next; tq = tq->Next;
	}
	//truong hop ra so am
	if (don_vi == 1) {
		tp = q.head; tq = p.head;
		int don_vi = 0;
		while (tp != NULL || tq != NULL) {
			int value = tp->Data - tq->Data - don_vi;
			if (value < 0) {
				value = tp->Data + 10 - tq->Data - don_vi;
				don_vi = 1;
			}
			else don_vi = 0;
			Add_head(res2, value);
			tp = tp->Next; tq = tq->Next;
		}
		tp = res2.head;
		while (tp->Data == 0) tp = tp->Next;
		tp->Data *= -1;
		return res2;
	}
	return res;
}