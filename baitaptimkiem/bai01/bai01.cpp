#include <iostream>

void Input(int*, int);
void Output(int*, int);
void Linear_search(int*, int, int);
void Binary_search(int*, int, int);


int main()
{
	int* a, n;
	std::cin >> n;
	a = new int[n+1];
	Input(a, n);
	int x; std::cin >> x;
	Linear_search(a, n, x);
	std::cout << '\n';
//	Binary_search(a, n, x); : mang ngau nhien khong duoc sap xep khong the thuc hien tknp.
	Output(a, n);

    //giai phong heap
	delete[] a;
	a = NULL;
}

void Input(int* a, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) a[i] = rand() % 1001;
	a[n] = 0;
}

void Output(int* a, int n) {
	for (int i = 0; i < n; i++) std::cout << a[i] << ' ';
	std::cout << '\n';
}

void Linear_search(int* a, int n, int x) {
	clock_t start, end;  //kieu du lieu thoi gian
	start = clock();
	a[n] = x;
	int i = 0;
	while (a[i] != x) i++;
	if (i == n) std::cout << "khong tim thay" << '\n';
	else std::cout << "vi tri: " << i << '\n';
	//time measure
	end = clock();
	double t = (double)(end - start) / CLOCKS_PER_SEC;
	std::cout << t;
}