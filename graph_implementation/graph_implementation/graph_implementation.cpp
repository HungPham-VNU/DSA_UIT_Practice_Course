#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int v, e;
	cin >> v >> e;

	vector<vector<int>> Graph(v, vector<int>(v, 0));

	//nhap do thi
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		Graph[x][y] = Graph[y][x] = 1;
	}
	
	//xuat do thi
	cout << '\n';
	for (int i = 0; i < Graph.size(); i++) {
		for (int j = 0; j < Graph[i].size(); j++)
			cout << Graph[i][j] << " \n"[j == Graph[i].size() - 1];
	}
		
}
