#include <iostream>

using namespace std;

int N, M, K;
int result = -10001;
int board[12][12];
bool visit[12][12];
pair<int, int> checkList[4]{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

void myFunc(int count, int sum) {
	if (count == K) {
		if (result < sum) {
			result = sum;
		}
		return;
	}

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			bool check = true;
			if (visit[n][m]) {
				check = false;
			}
			for (int checkCount = 0; checkCount < 4; checkCount++) {
				if (visit[n + checkList[checkCount].first][m + checkList[checkCount].second]) {
					check = false;
				}
			}

			if (check) {
				visit[n][m] = true;
				myFunc(count + 1, sum + board[n][m]);
				visit[n][m] = false;
			}
		}
	}
	return;
}

int main() {
	cin >> N >> M >> K;

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cin >> board[n][m];
		}
	}

	myFunc(0, 0);
	cout << result;

	return 0;
}
