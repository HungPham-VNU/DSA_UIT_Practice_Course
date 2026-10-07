#include <iostream>


bool Prime_check(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}


void Prime_search(int* a, int n) {
	for (int i = 0; i < n; i++)
		if (a[i] % 2 != 0) {
			if (Prime_check(a[i])) std::cout << a[i] << ' ';
		}
}


int main()
{
	int a[] = { 13, 27, 3, 5, 10, 20 };
	int n = sizeof(a) / sizeof(a[0]);
	 	Prime_search(a, n);
	return 0;
}