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
int Count_method_2(TREE);

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
//	Count(T);
//	std::cout << res;
	std::cout << Count_method_2(T);
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
		res++;
		Count(Root->Left);
		Count(Root->Right);
	}
}

int Count_method_2(TREE T) {
	if (T == NULL) return 0;
	else
		return 1 + Count_method_2(T->Left) + Count_method_2(T->Right);
}