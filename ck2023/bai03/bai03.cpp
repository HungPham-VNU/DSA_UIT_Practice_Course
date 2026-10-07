#include <iostream>
using namespace std;

struct Node {
	int Data;
	Node* Left;
	Node* Right;
};
typedef Node* TREE;

int AddNode(TREE& T, int x) {
	if (T != NULL)
	{
		if (T->Data > x) return AddNode(T->Left, x);
		if (T->Data < x) return AddNode(T->Right, x);
		if (T->Data == x) return 0;
	}
	T = new Node;
	T->Data = x;
	T->Left = NULL;
	T->Right = NULL;
    return 1;
}

void NLR(TREE T) {
	if (T != NULL) {
		cout << T->Data << ' ';
		NLR(T->Left);
		NLR(T->Right);
	}
	return;
}


int main()
{
	int n, x;
	cin >> n;
	TREE T = NULL;
	for (int i = 0; i < n; i++) {
		cin >> x;
		AddNode(T, x);
	}
//	NLR(T);



	return 0;
}