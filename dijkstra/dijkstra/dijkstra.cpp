#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
int pre[1000];
vector<vector<pair<int, int>>> adj;
int v, e;

void Dijkstra(int s, int t)
{
	vector<long long> d(v + 1, INF);
	d[s] = 0;
	pre[s] = s;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>>> Q;
	Q.push({ 0, s });
	while (!Q.empty()) {
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if (kc > d[u]) continue;
		for (auto it : adj[u]) {
			int v = it.first;
			int w = it.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pre[v] = u;
				Q.push({ d[v],v });
			}
		}
	}
	for (int i = 0; i < v; i++) cout << d[i] << ' ';
	cout << '\n';
}

int main()
{
	cin >> v >> e;
	for (int i = 0; i < v; i++) {
		vector<pair<int, int>> temp;
		adj.push_back(temp);
	}

	for (int i = 0; i < e; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		adj[x].push_back({y,k});
		adj[y].push_back({ x,k });
	}
	int x, y;
	cin >> x >> y;
	Dijkstra(x, y);
}