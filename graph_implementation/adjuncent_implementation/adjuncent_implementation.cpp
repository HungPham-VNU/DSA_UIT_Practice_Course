#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v);

	//nhap do thi
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	//xuat do thi
	for (int i = 0; i < v; i++) {
		cout << "Dinh " << i << ": ";
		for (int it : adj[i]) cout << it << ' ';
		cout << '\n';
	}

}