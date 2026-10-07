#include <iostream>


struct Node {
	int Key;
	Node* Left;
	Node* Right;
};
int res = 0;
typedef Node* TREE;
void Create_Tree(TREE&);
Node* Create_Node(int);
int InsertNode(TREE&, int);
void Count(TREE);

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
	Count(T);
	std::cout << res;
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

void Count(TREE Root) {
	if (Root != NULL) {
		if ((Root->Left != NULL && Root->Right == NULL) || (Root->Right != NULL && Root->Left == NULL)) res++;
		Count(Root->Left);
		Count(Root->Right);
	}
}