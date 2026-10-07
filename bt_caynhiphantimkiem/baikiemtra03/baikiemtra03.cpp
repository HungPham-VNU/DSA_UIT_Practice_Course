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
void BalanceNode(TREE);
int CountNode(TREE);

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
//	LNR(T);
	
    BalanceNode(T);
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

void LNR(TREE Root) {
	if (Root != NULL) {
		LNR(Root->Left);
		std::cout << Root->Key << ' ';
		LNR(Root->Right);
	}
	else return;
}

int CountNode(TREE T) {
	if (T == NULL) return 0;
	else return 1 + CountNode(T->Left) + CountNode(T->Right);
}


void BalanceNode(TREE T) {
	if (T != NULL) {
		BalanceNode(T->Left);
		int dem1 = CountNode(T->Left);
		int dem2 = CountNode(T->Right);
		if (dem1 == dem2 && dem1 != 0) std::cout << T->Key << ' ';
		BalanceNode(T->Right);
	}
	else return;
}

//recursion