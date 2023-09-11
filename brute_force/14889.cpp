#include <iostream>
#include <math.h>

using namespace std;

int N;
int ability[21][21];
int check[21];
int result = 2100000000;

void myFun(int start, int amount) {
	if (amount == N / 2) {
 		int startTeam = 0;
		int linkTeam = 0;
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (check[y] == 1 && check[x] == 1) {
					startTeam += ability[y][x];
				}
				else if (check[y] == 0 && check[x] == 0) {
					linkTeam += ability[y][x];
				}
			}
		}

		int diff = abs(startTeam - linkTeam);
		if (diff < result) {
			result = diff;
		}
	}
	else {
		for (int num = start; num <= N; num++) {
			check[num] = 1;
			myFun(num + 1, amount + 1);
			check[num] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> ability[y][x];
		}
	}

	myFun(1, 0);

	cout << result;

	return 0;
}
