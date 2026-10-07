#include <iostream>
using namespace std;

void Input(int*, int&);
void Output(int*, int);
void Selection_sort_a(int*, int, int);
void Selection_sort_b(int*, int, int);

int main()
{
	int a[100], n;
	Input(a, n);
	Selection_sort_b(a, 0, n - 1);
	Selection_sort_a(a, 0, n - 1);
	Output(a, n);
	return 0;
}

void Input(int* a, int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
}

void Selection_sort_a(int* a, int left, int right) {
	int min = 0;
	for (int i = left; i <= right; i++) {
		if (a[i] < 0) {
			min = i;
			for (int j = i; j <= right; j++) {
				if (a[min] > a[j] && a[j] < 0) min = j;
			}
			if (min != i) std::swap(a[min], a[i]);
		}
	}
}

void Selection_sort_b(int* a, int left, int right) {
	int max = 0;
	for (int i = left; i <= right; i++) {
		if (a[i] > 0) {
			max = i;
			for (int j = i; j <= right; j++) {
				if (a[max] < a[j] && a[j] > 0) max = j;
			}
			if (max != i) std::swap(a[max], a[i]);
		}
	}
}

void Output(int* a, int n) {
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
}