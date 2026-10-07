#include <iostream>
using namespace std;

struct Point {
	float x, y;
};
Point a[1000];
int n;
int Search(Point, Point*, int);
float Distance(Point, Point);


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	Point p; cin >> p.x >> p.y;
	cout << Search(p, a, n);
	return 0;
}

int Search(Point p, Point* a, int n) {
	float f[1000];
	for (int i = 0; i < n; i++) f[i] = Distance(p, a[i]);
	int index = 0, res = f[0];
	for (int i = 0; i < n; i++) {
		if (res < f[i]) {
			res = f[i];
			index = i;
		}
	}
//	for (int i = 0; i < n; i++) cout << f[i] << ' '; cout << '\n';
	return index;
}

float Distance(Point m, Point n) {
	return sqrt((m.x - n.x) * (m.x - n.x) + (m.y - n.y) * (m.y - n.y));
}
