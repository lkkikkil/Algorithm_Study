#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[10001];
int myStack[10];

void myPrint(int length) {
	if (length == m) {
		for (int idx = 0; idx < m; idx++) {
			cout << myStack[idx] << " ";
		}
		cout << "\n";
	}
	else {
		for (int numIndex = 0; numIndex < n; numIndex++) {
			myStack[length] = num[numIndex];
			myPrint(length + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int numCount = 0; numCount < n; numCount++) {
		cin >> num[numCount];
	}
	sort(num, num + n);

	myPrint(0);

	return 0;
}
