#include <iostream>

int n, a[105];

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    
    int min = 0;
    for (int i = 1; i <= n; i++) {
        min = i;
        for (int j = i; j <= n; j++) {
            if (a[min] > a[j]) min = j;
        }
        if (min != i) std::swap(a[min], a[i]);
    }

    for (int i = 1; i <= n; i++) std::cout << a[i] << " ";

}