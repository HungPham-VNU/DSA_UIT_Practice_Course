#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int v, e;
vector<bool> visited;
vector<set<int>> adj;

void Output() {
	cout << '\n';
	for (int i = 0; i < v; i++) {
		for (auto it : adj[i]) cout << it << ' ';
		cout << '\n';
	}
}

void DFS(int u) {
	visited[u] = true;
	cout << u << ' ';
	for (int v : adj[u]) {
		if (!visited[v]) DFS(v);
	}
}

void SetGraph(vector<set<int>>& adj, vector<bool>& visited) {
	cin >> v >> e;
	for (int i = 0; i < v; i++) visited.push_back(false);
	
	for (int i = 0; i < v; i++) {
		set<int> temp;
		adj.push_back(temp);
	}

	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
}

void BFS(int u) {
	queue<int> q;
	q.push(u); visited[u] = true;
	cout << u << ' ';

	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				q.push(x); visited[x] = true;
				cout << x << ' ';
			}
		}
	}
}


int main()
{
	SetGraph(adj, visited);

	Output();

	cout << "DFS: "; DFS(0); cout << '\n';

	for (int i = 0; i < visited.size(); i++) visited[i] = false;
	cout << "BFS: "; BFS(0); cout << '\n';

}