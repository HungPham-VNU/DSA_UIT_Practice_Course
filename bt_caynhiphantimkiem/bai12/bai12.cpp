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
void NLR(TREE);
void DeleteNodeX1(TREE&, int);
void ThayThe1(TREE&, TREE&);

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
	int k;
	std::cin >> k;
	DeleteNodeX1(T, k);
	NLR(T);
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

void DeleteNodeX1(TREE& T, int x)
{
	if (T != NULL)
	{
		if (T->Key < x) DeleteNodeX1(T->Right, x);
		else if (T->Key > x) DeleteNodeX1(T->Left, x);
		else
		{
			Node* p = T;
			if (T->Left == NULL) T = T->Right;
			else if (T->Right == NULL) T = T->Left;
			else
				ThayThe1(p, T->Left);
			delete p;
		}
	}
}

void ThayThe1(TREE& p, TREE& T)
{
	if (T->Left != NULL)
		ThayThe1(p, T->Right);
	else
	{
		p->Key = T->Key; p = T;
		T = T->Left;
	}
}