#include <iostream>
#include <vector>
using namespace std;

int Linear_search(vector<int>, int);


int main()
{
    vector<int> a = { 1, 2, 3, 4, 5 };
    int x; cin >> x;
    cout << Linear_search(a, x);
    return 0;
}

//ky thuat linh canh
int Linear_search(vector<int> p, int k) {
    p.push_back(k);
    int i = 0;
    while (p[i] != k) i++;
    if (i == p.size() - 1) return -1;
    return i;
}