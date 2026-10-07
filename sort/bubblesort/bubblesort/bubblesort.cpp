#include <iostream>
#include <algorithm>


int main()
{
	int n, a[30];
	std::cin >> n;
	for (int i = 0; i < n; i++) std::cin >> a[i];

	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) std::swap(a[j], a[j - 1]);
		}

	for (int i = 0; i < n; i++) std::cout << a[i] << " ";

}