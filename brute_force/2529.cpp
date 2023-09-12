#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int operAmount;
char orederList[9];
int check[10];
string currentNum = "";
string maxNum = "-1";
string minNum = "9999999999";

bool operCheck(char oper, char frontNum, char backNum) {
	if (oper == '<') {
		if (frontNum < backNum) {
			return true;
		}
	}
	else {
		if (frontNum > backNum) {
			return true;
		}
	}
	return false;
}

void myMax(int length) {
	if (length == operAmount + 1) {
		maxNum = max(currentNum, maxNum);
	}
	else {
		for (int num = 9; num >= 0; num--) {
			if (check[num] == 1) {
				continue;
			}
			else {
				if (length == 0 || operCheck(orederList[length - 1], currentNum[length - 1], num + '0')) {
					check[num] = 1;
					currentNum += num + '0';
					myMax(length + 1);
					check[num] = 0;
					currentNum.erase(length, 1);
				}
			}
		}
	}
}

void myMin(int length) {
	if (length == operAmount + 1) {
		minNum = min(currentNum, maxNum);
	}
	else {
		for (int num = 9; num >= 0; num--) {
			if (check[num] == 1) {
				continue;
			}
			else {
				if (length == 0 || operCheck(orederList[length - 1], currentNum[length - 1], num + '0')) {
					check[num] = 1;
					currentNum += num + '0';
					myMin(length + 1);
					check[num] = 0;
					currentNum.erase(length, 1);
				}
			}
		}
	}
}

int main() {
	cin >> operAmount;
	for (int operCount = 0; operCount < operAmount; operCount++) {
		cin >> orederList[operCount];
	}

	myMax(0);
	currentNum = "";
	for (int index = 0; index <= 9; index++) {
		check[index] = 0;
	}
	myMin(0);

	cout << maxNum << "\n" << minNum;

	return 0;
}
