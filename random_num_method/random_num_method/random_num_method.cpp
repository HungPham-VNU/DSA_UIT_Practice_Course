#include <iostream>
using namespace std;

void Input(int*, int&);
void Output(int*, int);

int main()
{
	int* a = NULL;
	int n = 0;
	cin >> n;
	a = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) a[i] = rand() % 1001;
	Output(a, n);
	delete[] a;
}

//void Input(int* a, int& n) {
//	cin >> n;
//	a = new int[n];
//	srand(time(NULL));
//	for (int i = 0; i < n; i++) a[i] = rand() % 1001;
//}

void Output(int* a, int n) {
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
}