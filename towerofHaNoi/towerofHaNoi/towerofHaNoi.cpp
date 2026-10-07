#include <iostream>

void TowerofHaNoi(int n, char start, char temp, char end);

int main() {
	int n;
	std::cin >> n;
	TowerofHaNoi(n, 'A', 'B', 'C');
	return 0;
}


void TowerofHaNoi(int n, char start, char temp, char end) {
	if (n == 1) std::cout << start << "->" << end << '\n';
    else {
		TowerofHaNoi(n - 1, start, end, temp);
		TowerofHaNoi(1, start, temp, end);
		TowerofHaNoi(n - 1, temp, start, end);
	}
}

//do phuc tap: O(2^n + 1)