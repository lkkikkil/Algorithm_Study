#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[10001];
int visit[10001];
int myStack[10];

void myPrint(int startIndex,int length) {
	if (length == m) {
		for (int idx = 0; idx < m; idx++) {
			cout << myStack[idx] << " ";
		}
		cout << "\n";
	}
	else {
		for (int numIndex = startIndex; numIndex < n; numIndex++) {
			if (visit[numIndex] == 0) {
				visit[numIndex] = 1;
				myStack[length] = num[numIndex];
				myPrint(numIndex + 1 ,length + 1);
				visit[numIndex] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int numCount = 0; numCount < n; numCount++) {
		cin >> num[numCount];
	}
	sort(num, num + n);

	myPrint(0, 0);

	return 0;
}
