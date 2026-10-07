#include <iostream>
#pragma warning(disable: 6385)
#pragma warning(disable: 6386)

void MergeSort(int*, int, int);
void Merge(int*, int, int, int);

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
	int* temp = new int[Right - Left + 1];
	int m = 0;
	int i = Left;
	int j = Mid + 1;

	while (i <= Mid || j <= Right) {
		if ((a[i] < a[j] && (j <= Right) && (i <= Mid)) || (j > Right))
			temp[m++] = a[i++];
		else
			temp[m++] = a[j++];
	}

	for (i = 0; i < m; i++)
		a[Left + i] = temp[i];
	
	delete[] temp;
}

//implemented by Mer (15/06/2024)
//This is the upgraded version of Mergesort with the miminum use of memory. (idea: Dr. Nguyen Tan Tran Minh Khang)