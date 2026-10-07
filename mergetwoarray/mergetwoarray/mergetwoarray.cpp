#include <iostream>
#include <vector>
using std::vector;
void Merge(int*, int, int*, int, vector<int>&);

int main()
{
	int a[] = { 15, 27, 32, 64 };
	int n = sizeof(a) / sizeof(a[0]);
	int b[] = { -5, 1, 18, 29, 37, 56, 80, 93 };
	int m = sizeof(b) / sizeof(b[0]);
	vector<int> c;
	Merge(a, n, b, m, c);
	for (int i : c) std::cout << i << ' ';
	return 0;
}

void Merge(int* a, int n, int* b, int m, vector<int>& c) {
	int i = 0;
	int j = 0;

	while (i < n || j < m) {
		if ((a[i] < b[j] && i < n) || (j >= m))
			c.push_back(a[i++]);
		else
			c.push_back(b[j++]);
	}
}