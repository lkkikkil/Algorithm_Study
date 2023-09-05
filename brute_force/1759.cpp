#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char alphabets[15];
char printArray[15];

void myFunc(int l, int startIndex) {
	if (l == L) {
		int check = 0;
		for (int printCount = 0; printCount < L; printCount++) {
			switch (printArray[printCount]) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					check++;
				default:
					break;
			}
		}
		if (check >= 1 && L - check >= 2) {
			for (int printCount = 0; printCount < L; printCount++) {
				cout << printArray[printCount];
			}
			cout << "\n";
		}
	}
	else {
		for (int visitCount = startIndex; visitCount < C; visitCount++) {
			printArray[l] = alphabets[visitCount];
			myFunc(l + 1, visitCount + 1);
		}
	}
}

int main() {
	cin >> L >> C;
	for (int c = 0; c < C; c++) {
		cin >> alphabets[c];
	}

	sort(alphabets, alphabets + C);

	myFunc(0, 0);

	return 0;
}
