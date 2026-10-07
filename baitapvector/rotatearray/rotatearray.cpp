#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
vector<int> v;
int n, k;


void Rotate_method_1() {
	int j = 1;
	while (j <= k) {
		v.insert(v.begin(), v.back());
		v.erase(v.begin() + v.size() - 1);
		j++;
	}
	for (int i = 0; i < v.size(); i++) std::cout << v[i] << ' ';
}

void Rotate_method_2() {
	int j = 1;
	while (j <= k) {
		std::rotate(v.begin(), v.end() - 1, v.end());
		j++;
	}
	for (auto i = v.begin(); i != v.end(); i++) std::cout << *i << ' ';
}

int main()
{
	std::cin >> n >> k;
	int x;
	while (n--) {
		std::cin >> x;
		v.push_back(x);
	}
	Rotate_method_1();
//	Rotate_method_2();
	return 0;
}