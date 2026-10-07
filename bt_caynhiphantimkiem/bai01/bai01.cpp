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
void LNR(TREE);
void RNL(TREE);
void NLR(TREE);

int main()
{
	TREE T;
	Create_Tree(T);
	int x;
	while (1) {
		std::cin >> x;
		if (x == -1) break;
		InsertNode(T, x);
	}
	LNR(T);
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

void LNR(TREE Root) {
	if (Root != NULL) {
		LNR(Root->Left);
		std::cout << Root->Key << ' ';
		LNR(Root->Right);
	}
	else return;
}

void RNL(TREE Root) {
	if (Root != NULL) {
		RNL(Root->Right);
		std::cout << Root->Key << ' ';
		RNL(Root->Left);
	}
}

void NLR(TREE Root) {
	if (Root != NULL) {
		std::cout << Root->Key << ' ';
		NLR(Root->Left);
		NLR(Root->Right);
	}
}
