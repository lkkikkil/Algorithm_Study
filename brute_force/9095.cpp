#include <iostream>

using namespace std;

int main() {
	int result[12]{ 0, 1, 2, 4 };
	for (int i = 4; i < 12; i++) {
		result[i] = result[i - 1] + result[i - 2] + result[i - 3];
	}

	int caseAmount;
	cin >> caseAmount;
	for (int caseCount = 0; caseCount < caseAmount; caseCount++) {
		int num;
		cin >> num;

		cout << result[num] << "\n";
	}

	return 0;
}
