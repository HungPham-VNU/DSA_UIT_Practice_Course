// quick sort
#include <iostream>
using namespace std;

void Quicksort(int*, int, int);
int Partition(int*, int, int);

int main()
{
	int a[40];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	Quicksort(a, 0, n - 1);

	for (int i = 0; i < n; i++) cout << a[i] << ' ';
}

void Quicksort(int* a, int lo, int hi)
{
	if (lo < hi)
	{
		int m = Partition(a, lo, hi);
		Quicksort(a, lo, m - 1);
		Quicksort(a, m + 1, hi);
	}
	else return;
}

int Partition(int* a, int lo, int hi)
{
	int pivot = lo;
	int i = lo + 1;
	int j = hi;

	while (i <= j) {
		while (a[i] < a[pivot] && i < hi) i++;
		while (a[j] > a[pivot] && j > lo) j--;
		if (i <= j) swap(a[i++], a[j--]);
	}
	swap(a[pivot], a[j]);
	return j;
}