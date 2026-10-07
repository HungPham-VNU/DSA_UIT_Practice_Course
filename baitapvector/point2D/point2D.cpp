#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
int n;
struct Point {
	float x;
	float y;
};


bool order(Point m, Point n) {
	if (m.x == n.x) return m.y > n.y;
	return m.x < n.x;
}


int main()
{
	std::cin >> n;
	vector<Point> v(n);
	for (int i = 0; i < n; i++) std::cin >> v[i].x >> v[i].y;
	std::sort(v.begin(), v.end(), order);
	for (int i = 0; i < v.size(); i++) std::cout << v[i].x << ' ' << v[i].y << '\n';
	return 0;
}