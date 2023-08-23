#include <iostream>

using namespace std;

int n, m;
int visit[10];
int myStack[10];

void myPrint(int length) {
	if (length == m) {
		for (int idx = 0; idx < m; idx++) {
			cout << myStack[idx] << " ";
		}
		cout << "\n";
	}
	else {
		for (int num = 1; num <= n; num++) {
			if ((length == 0 || myStack[length - 1] < num) && visit[num] == 0) {
				visit[num] = 1;
				myStack[length] = num;
				myPrint(length + 1);
				visit[num] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	myPrint(0);

	return 0;
}
