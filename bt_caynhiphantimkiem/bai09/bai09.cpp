#include <iostream>


struct Node {
	int Key;
	Node* Left;
	Node* Right;
};
typedef Node* TREE;
void Create_Tree(TREE&);
Node* Create_Node(int);
int InsertNode(TREE&, int);
void Output(TREE, int&, int);

int main()
{
	TREE T;
	Create_Tree(T);
	int x;
	while (1) {
		std::cin >> x;
		if (x == 0) break;
		InsertNode(T, x);
	}
	//	std::cout << Height(T);
	int T_max = 0, h = 0;  // h co the duoc su dung cho bai toan duyet theo muc
//	Output(T, T_max, h);
	return 0;
}

void Create_Tree(TREE& T) {
	T = NULL;
}

Node* Create_Node(int x) {
	Node* p;
	p = new Node;
	if (p == NULL) exit(1);
	else {
		p->Key = x;
		p->Left = NULL;
		p->Right = NULL;
	}
	return p;
}

int InsertNode(TREE& T, int x) {
	if (T != NULL) {
		if (T->Key == x) return 0;
		if (T->Key > x) return InsertNode(T->Left, x);
		else return InsertNode(T->Right, x);
	}
	T = Create_Node(x);
	return 1;
} // lam sao T co the giu dia chi cua Root sau ham de quy nay?

int Height(TREE T) {
	if (T == NULL) return 0;
	else
		return std::max(Height(T->Left), Height(T->Right)) + 1;
}
