#include <iostream>
using namespace std;

int n;
int a[10000 + 5];
int x;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    
    int index = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) cnt++;
    }
    if (cnt == 0) cout << cnt;
    else {
        cout << cnt << '\n';
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                cout << i << ' ' << i + 1 << '\n';
            }
        }
    }

}