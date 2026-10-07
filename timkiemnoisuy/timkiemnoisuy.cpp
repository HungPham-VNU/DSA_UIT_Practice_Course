#include <iostream>
#include <vector>
using namespace std;


int Interpolation_search(vector<int>, int);

int main()
{
	int x; cin >> x;
	vector<int> v = { 1, 2, 3, 4, 9, 10, 12, 14 };
	cout << Interpolation_search(v, x);
	return 0;
}

//tim kiem noi suy
int Interpolation_search(vector<int> p, int k) {
	int l = 0, r = p.size() - 1;
	int m = l + ((r - l) * (k - p[l])) / (p[r] - p[l]);
	while (l <= r) {
		if (p[m] == k) return m;
		if (p[m] < k) l = m + 1;
		else r = m - 1;
		m = l + ((r - l) * (k - p[l])) / (p[r] - p[l]);
	}
	return -1;
}