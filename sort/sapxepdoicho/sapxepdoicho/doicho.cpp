#include <iostream>
#include <algorithm>
int n, a[5];

int main()
{
	std::cin >> n;
	for (int i = 0; i < n; i++) std::cin >> a[i];
	
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i]) std::swap(a[i], a[j]);

	for (int i = 0; i < n; i++) std::cout << a[i] << " ";
}


// this's called "interchange sort"