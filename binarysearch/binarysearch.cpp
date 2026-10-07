#include <iostream>
using namespace std;

int Binary_search(int*, int, int);

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 10 };
	int n = sizeof(a) / sizeof(a[0]);
	int x; cin >> x;
	cout << Binary_search(a, x, n);
	return 0;
}

int Binary_search(int A[], int k, int n) {
	int l = 0, r = n - 1;
	int mid = (l + r) / 2;
	while (l <= r) {
		if (A[mid] == k) return mid;
		if (A[mid] < k) l = mid + 1;
		else r = mid - 1;
		mid = (l + r) / 2;
	}
	return -1;
}