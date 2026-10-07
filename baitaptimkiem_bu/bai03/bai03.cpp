#include <iostream>
using namespace std;
int a[32000 + 5];
void Binary_search(int*, int, int);
int cnt = 0;
int Binary_search_2(int*, int, int);

int main()
{
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int x; 
	cin >> x;
//	Binary_search(a, x, n);
	cnt = 0;

//	cout << '\n' << Binary_search(a, x, n);
//	if (Binary_search(a, x, n) != -1) cout << '\n' << cnt;
	int temp = Binary_search_2(a, x, n);
	cout << temp << '\n' << cnt;

	return 0;
}

void Binary_search(int A[], int k, int n) 
{
	int res = -1;
	int l = 0, r = n - 1;
	int mid = (l + r) / 2;
	while (l <= r) 
	{
//		cout << ++cnt << '\n';
		cnt++;
		if (A[mid] == k)
		{
			res = mid;
			break;
		}
		if (A[mid] < k) l = mid + 1;
		else r = mid - 1;
		mid = (l + r) / 2;
	}
	if (res == -1)
		cout << res;
	else 
		cout << res << '\n' << cnt;
}


int Binary_search_2(int* a, int k, int n)
{
	int l = 0;
	int r = n - 1;
	int mid = (l + r) / 2;
	while (l <= r)
	{
		cnt++;
		if (a[mid] == k) return mid;
		if (a[mid] < k) l = mid + 1;
		else r = mid - 1;
		mid = (l + r) / 2;
	}
	return -1;
}
