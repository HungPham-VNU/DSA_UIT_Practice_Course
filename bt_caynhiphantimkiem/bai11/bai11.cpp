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
int Count(TREE);

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
	Count(T, a);
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
}


int Count(TREE T) {
	if (T == NULL) return 0;
	else {
		int a = 1 + Count(T->Left);

	}


}