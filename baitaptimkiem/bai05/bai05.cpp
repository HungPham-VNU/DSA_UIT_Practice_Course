#include <iostream>
using namespace std;
int a[1000+5], f[1000+5], n;

void Solve(int* a, int n) {
	f[0] = 1;
	int res = 0;
	for (int i = 1; i < n; i++) {
		f[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && f[j] + 1 > f[i]) f[i] = f[j] + 1;
		}
	}

	for (int i = 0; i < n; i++) res = max(res, f[i]);
	cout << res;
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	Solve(a, n);
	return 0;
}