#include <iostream>
#pragma warning(disable: 6385)

void MergeSort(int*, int, int);
void Merge(int*, int, int, int);
void Tron(int*, int, int*, int, int*, int&);

int main()
{
	int a[] = { 20, 30, 50, 100, 20, 40 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort(a, 0, n - 1);
	for (int i = 0; i < n; i++) std::cout << a[i] << ' ';
}

void MergeSort(int* a, int Left, int Right) {
	if (Left < Right) {
		int Mid = (Left + Right) / 2;
		MergeSort(a, Left, Mid);
		MergeSort(a, Mid + 1, Right);
		Merge(a, Left, Mid, Right);
	}
}

void Merge(int* a, int Left, int Mid, int Right) {
	int* b = new int[Mid - Left + 1];
	int k;
	int* c = new int[Right - Mid];
	int l;
	int* temp = new int[Right - Left + 1];
	int m = 0;

	k = 0;
	for (int i = Left; i <= Mid; i++)
		b[k++] = a[i];
	l = 0;
	for (int i = Mid + 1; i <= Right; i++)
		c[l++] = a[i];
	Tron(b, k, c, l, temp, m);
	for (int i = 0; i < m; i++)
		a[Left + i] = temp[i];
	delete[] b;
	delete[] c;
	delete[] temp;
}

void Tron(int* a, int n, int* b, int m, int* c, int& l) {
	int i = 0;
	int j = 0;

	while (i < n || j < m) {
		if ((a[i] < b[j] && i < n) || (j >= m))
			c[l++] = a[i++];
		else
			c[l++] = b[j++];
	}
}

//implemented by Mer (15/06/2024)
//the standard version of MergeSort (use for reviewing algorithms or teaching purposes)