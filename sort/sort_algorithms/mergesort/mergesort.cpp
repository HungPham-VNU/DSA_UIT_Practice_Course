#include <iostream>
#pragma warning(disable: 6001)
using namespace std;

void Merge(int arr[], int l, int m, int r) {
	int* L = new int[m - l + 1];
	int* R = new int[r - m];

	int n1 = 0;
	for (int i = l; i <= m; ++i)
		L[n1++] = arr[i];
	int n2 = 0;
	for (int j = m + 1; j <= r; ++j)
		R[n2++] = arr[j];

	int i = 0, j = 0, k = l;
	while (i < n1 || j < n2)
	{
		if (((L[i] < R[j]) && (i < n1)) || (j >= n2))
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	delete[] L;
	delete[] R;
}

void MergeSort(int arr[], int l, int r) {
	if (l < r)
	{
		int m = (r + l) / 2;
		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);
		Merge(arr, l, m, r);
	}
}

int main()
{
	int arr[] = { 2, 9, 1, 8, 6, 4, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	return 0;
}

//implemented based on BHTCNPM-Materials (15/06/2024)