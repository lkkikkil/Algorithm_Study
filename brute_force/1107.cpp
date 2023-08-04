#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {	
	int channel;
	cin >> channel;

	int errBtnAmount;
	cin >> errBtnAmount;

	int btnList[10]{ 1,1,1,1,1,1,1,1,1,1 };
	for (int errBtnCheck = 0; errBtnCheck < errBtnAmount; errBtnCheck++) {
		int btnNum;
		cin >> btnNum;

		btnList[btnNum] = 0;
	}

	int btnCount = abs(channel - 100);
	for (int num = 0; num < 1000000; num++) {
		string s_num = to_string(num);
		
		bool errCheck = true;
		int numLenght = s_num.length();
		for (int numCheck = 0; numCheck < numLenght; numCheck++) {
			if (btnList[s_num[numCheck] - '0'] == 0) {
				errCheck = false;
			}
		}

		if (errCheck) {
			int curBtnCount = abs(channel - num) + numLenght;
			if (btnCount > curBtnCount) {
				btnCount = curBtnCount;
			}
		}
	}

	cout << btnCount;

	return 0;
}
