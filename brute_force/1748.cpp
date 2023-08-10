#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;

	int length = 0;
	for (int amountCount = 1; amountCount <= num; amountCount *= 10) {
		length += num - amountCount + 1;
	}

	cout << length;

	return 0;
}
