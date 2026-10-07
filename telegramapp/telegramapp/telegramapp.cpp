#include <iostream>
#include <stack>
using namespace std;

int k, n, a[1000];

int main()
{
    stack<int> myStack;
    cin >> k;
    cin >> n;

    int x = 0;
    while (n--) {
        cin >> x;
        myStack.push(x);
        a[x]++;
    }

    while (k != 0 && (!myStack.empty())) {
        x = myStack.top();
        myStack.pop();
        if (a[x] != 0) {
            cout << x << '(' << a[x] << ')' << ' ';
            a[x] = 0;
            k--;
        }
    }
}