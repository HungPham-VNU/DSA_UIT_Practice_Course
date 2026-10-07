#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> p;
	//p.push(1);
	//p.push(2);
	//p.push(3);
	//p.push(4);
	int c = 0;

	p.emplace(1);
	p.emplace(2);
	p.emplace(3);
	p.emplace(4);

	while (!p.empty()) {
		cout << p.top() << ' ';
		p.pop();
		c++;
	}
//	cout << c;
	return 0;
}