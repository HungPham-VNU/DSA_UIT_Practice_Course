#include <iostream>


int Binary_search(int* a, int x, int low, int high) {
    int mid = (low + high) / 2;
    if (low >= high) return 0;
    if (a[mid] == x) return mid;
    if (a[mid] > x) return Binary_search(a, x, low, mid - 1);
    if (a[mid] < x) return Binary_search(a, x, mid + 1, high);
}


int main()
{
    int a[] = { 3, 5, 10, 15, 20, 26 };
    int n = sizeof(a) / sizeof(a[0]);
    int x = 0; std::cin >> x;
    if (Binary_search(a, x, 0, n) == 0) std::cout << "Khong tim thay";
    else std::cout << Binary_search(a, x, 0, n);
    return 0;
}