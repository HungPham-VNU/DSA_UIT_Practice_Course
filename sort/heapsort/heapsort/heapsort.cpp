#include <iostream>
#include <algorithm>
using std::max;


void Outp(int*, int);
void Heapify(int*, int, int);
void Heapsort(int*, int);


int main()
{
	int a[] = { 20, 70, 80, 30, 50, 10};
	int n = sizeof(a) / sizeof(a[0]);
	Heapsort(a, n);
	Outp(a, n);
	return 0;
}

void Heapsort(int* a, int n) {
	for (int i = n / 2 - 1; i >= 0; i--) Heapify(a, i, n);
	for (int i = n - 1; i > 0; i--) {
		std::swap(a[0], a[i]);
		Heapify(a, 0, i);
	}
}

void Heapify(int* a, int j, int n) {
	int index_max = j;
	int l = 2 * j + 1, r = 2 * j + 2;
	if (l < n && a[l] > a[j]) index_max = l;
	if (r < n && a[r] > a[index_max]) index_max = r;
	if (index_max != j) {
		std::swap(a[j], a[index_max]);
		Heapify(a, index_max, n); // lan truyen hieu chinh: khi thay doi nut index_max -> nut nho hon -> tiep tuc xet nut con
	}
}

void Outp(int* a, int m) {
	for (int i = 0; i < m; i++) std::cout << a[i] << ' ';
}