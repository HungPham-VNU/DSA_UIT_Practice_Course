#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Heapsort(int*, int);
void Output(int*, int);

int main()
{
	int a[] = { 10, 50, 70, 20, 90, 80 };
	int n = sizeof(a) / sizeof(a[0]);
	Heapsort(a, n);
	Output(a, n);
	return 0;
}

void Heapsort(int* arr, int n) {
	vector<int> v(arr, arr + n); //convert array to vector
	make_heap(v.begin(), v.end());
	sort_heap(v.begin(), v.end());
	copy(v.begin(), v.end(), arr);
}

void Output(int* arr, int n) {
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}