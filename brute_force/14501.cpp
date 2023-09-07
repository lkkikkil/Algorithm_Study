#include <iostream>
#include <algorithm>

using namespace std;

int N, T[15], P[15];
int result;

void cal(int sum, int currnetDay) {
	if (currnetDay >= N) {
		if (sum > result) {
			result = sum;
		}
	}
	else {
		if (currnetDay + T[currnetDay] <= N) {
			cal(sum + P[currnetDay], currnetDay + T[currnetDay]);
		}
		cal(sum, currnetDay + 1);
	}
}

int main() {
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> T[n] >> P[n];
	}

	cal(0, 0);

	cout << result;

	return 0;
}
