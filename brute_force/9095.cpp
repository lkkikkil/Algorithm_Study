#include <iostream>

using namespace std;

int result(int _num) {
	if (_num == 1) return 1;
	else if (_num == 2) return 2;
	else if (_num == 3) return 4;
	else return result(_num - 1) + result(_num - 2) + result(_num - 3);
}

int main() {
	int caseAmount;
	cin >> caseAmount;
	for (int caseCount = 0; caseCount < caseAmount; caseCount++) {
		int num;
		cin >> num;

		cout << result(num) << "\n";
	}

	return 0;
}
