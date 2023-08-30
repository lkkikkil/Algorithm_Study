#include <iostream>

using namespace std;

int n, m;
int myStack[10];

void myPrint(int startNum, int length) {
	if (length == m) {
		for (int idx = 0; idx < m; idx++) {
			cout << myStack[idx] << " ";
		}
		cout << "\n";
	}
	else {
		for (int num = startNum; num <= n; num++) {
			myStack[length] = num;
			myPrint(num + 1, length + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	myPrint(1, 0);

	return 0;
}
