#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int A[] = { 0, 1, 2 };
vector<stack<int>> v(3);

void Move(int, int);
void Solve(int);

int main()
{
	int n;
	cin >> n;
	Solve(n);
	return 0;
}

void Move(int a, int b) {
	if (v[b].empty() || (!v[a].empty() && v[a].top() < v[b].top())) {
		cout << A[a] << "->" << A[b] << '\n';
		v[b].push(v[a].top());
		v[a].pop();
	}
	else
		Move(b, a);
}

void Solve(int n) {
	int first = 0, mid = 1, last = 2;
	int k = (1 << n) - 1; // so buoc can chuyen la 2^n - 1
	while (n--) {
		v[first].push(n);
	}
	if (n % 2 == 0) swap(mid, last);
	for (int i = 1; i <= k; i++) {
		if (i % 3 == 0) Move(mid, last);
		else if (i % 3 == 1) Move(first, last);
		else Move(first, mid);
	}
}