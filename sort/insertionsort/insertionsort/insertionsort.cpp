#include <iostream>
using namespace std;

void selection_sort(int*, int);
void Output(int*, int);

int main() {
	int a[] = { 20, 40, 10, 30, 90, 50 };
	int n = sizeof(a) / sizeof(a[0]);
	selection_sort(a, n);
	Output(a, n);
}

//idea: how to order card 
void selection_sort(int* a, int n) {
	for (int i = 1; i < n; i++)
		if (a[i] < a[i - 1]) {
			for (int j = i; j > 0; j--) {
				if (a[j - 1] > a[j]) swap(a[j], a[j - 1]);
			}
		}
}

void Output(int* a, int n) {
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
}