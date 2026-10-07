#include <iostream>
#include <time.h>

void Run(int);


int main() {
	int64_t n = 10000;
	Run(n);
}

void Run(int n) {
	clock_t start, end;  //kieu du lieu thoi gian
	start = clock();
	int sum = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) sum += i;
	end = clock();
	double t = (double)(end - start) / CLOCKS_PER_SEC;
	std::cout << t;
}