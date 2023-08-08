#include <iostream>

using namespace std;

int gcd (int num1, int num2) {
	if (num1 % num2 == 0) {
		return num2;
	}
	else {
		return gcd(num2, num1 % num2);
	}
}

int main() {
	int caseAmount;
	cin >> caseAmount;

	for (int caseCount = 0; caseCount < caseAmount; caseCount++) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int maxYear = (M * N) / gcd(M, N);
		int year = x;
		while ( year <= maxYear ) {
			if (year % N == y || (year % N == 0 && y == N)) {
				cout << year << "\n";
				break;
			}
			year += M;
		}
		if (year > maxYear) {
			cout << -1 << "\n";
		}
	}

	return 0;
}
