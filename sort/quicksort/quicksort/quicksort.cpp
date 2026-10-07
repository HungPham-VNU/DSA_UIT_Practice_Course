#include <iostream>
#include <algorithm> 
using namespace std;

//void Input(int*, int&);
void Output(int*, int);
void Quicksort(int*, int, int);
int Partition(int*, int, int);

int main()
{
	int a[] = { 10, 80, 30, 90, 40, 50, 70 };
	int n = sizeof(a) / sizeof(a[0]);
    Quicksort(a, 0, n - 1);
	Output(a, n);
}

void Quicksort(int* a, int lo, int hi) {
	if (lo >= hi) return; //base case
	random_shuffle(a + lo, a + hi); //rearrange the array
	int m = Partition(a, lo, hi);
	Quicksort(a, lo, m);
	Quicksort(a, m + 1, hi);
}

int Partition(int* a, int lo , int hi) {
	int pivot = lo;
	int i = lo + 1, j = hi;
	while (i <= j) {
		while (i < hi && a[i] < a[pivot]) i++;
		while (a[j] > a[pivot]) j--;
		if (i <= j) swap(a[i++], a[j--]);
	}
	swap(a[pivot], a[j]);
	return j;
}

void Output(int* a, int n) {
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
}

//implemented by Mer (22/03/2024)