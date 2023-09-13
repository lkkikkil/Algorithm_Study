#include <iostream>

using namespace std;

int maxLength;
char signList[10][10];
int sum[10];
int result[10];
bool funEnd = false;

bool check(int index, int currentNum) {
	for (int checkCount = index; checkCount >= 0; checkCount--) {
		if (signList[checkCount][index] == '+' && !(sum[checkCount] + currentNum > 0)) {
			return false;
		}
		else if (signList[checkCount][index] == '-' && !(sum[checkCount] + currentNum < 0)) {
			return false;
		}
		else if (signList[checkCount][index] == '0' && !(sum[checkCount] + currentNum == 0)) {
			return false;
		}
	}
	return true;
}

void myFun(int index) {
	if (index == maxLength) {
		funEnd = true;
		return;
	}
	else {
		for (int num = -10; num <= 10; num++) {
			if (funEnd) {
				break;
			}

			if (check(index, num)) {
				result[index] = num;
				for (int addIndex = 0; addIndex <= index; addIndex++) {
					sum[addIndex] += num;
				}
				myFun(index + 1);
				for (int addIndex = 0; addIndex <= index; addIndex++) {
					sum[addIndex] -= num;
				}
			}
		}

	}
}

int main() {
	cin >> maxLength;
	for (int y = 0; y < maxLength; y++) {
		for (int x = y; x < maxLength; x++) {
			cin >> signList[y][x];
		}
	}
	myFun(0);
	for (int index = 0; index < maxLength; index++) {
		cout << result[index] << " ";
	}

	return 0;
}
