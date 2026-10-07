#include <iostream>
#include <algorithm>  // std::random_shuffle


int main()
{
	int a[] = { 10, 30, 40, 50, 70 };
	int n = sizeof(a) / sizeof(a[0]);
	std::random_shuffle(a, a + n - 1);
	for (int i = 0; i < n; i++) std::cout << a[i] << ' ';
}
