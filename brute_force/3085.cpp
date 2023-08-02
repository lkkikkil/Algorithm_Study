#include <iostream>

using namespace std;

char board[51][51];

int maxCandy = 0;
void candyCheck(int _num) {
	char color;
	int curCandy;
	for (int y = 0; y < _num; y++) {
		for (int x = 0; x < _num - 1; x++) {
			color = board[y][x];
			curCandy = 1;
			while (color == board[y][x + 1]) {
				x++;
				curCandy++;
			}
			if (curCandy > maxCandy) {
				maxCandy = curCandy;
			}
		}
	}

	for (int x = 0; x < _num; x++) {
		for (int y = 0; y < _num - 1; y++) {
			color = board[y][x];
			curCandy = 1;
			while (color == board[y + 1][x]) {
				y++;
				curCandy++;
			}
			if (curCandy > maxCandy) {
				maxCandy = curCandy;
			}
		}
	}
}

int main() {
	int num;
	cin >> num;

	for (int y = 0; y < num; y++) {
		for (int x = 0; x < num; x++) {
			cin >> board[y][x];
		}
	}

	char tmpColor;
	for (int y = 0; y < num; y++) {
		for (int x = 0; x < num - 1; x++) {
			tmpColor = board[y][x];
			board[y][x] = board[y][x + 1];
			board[y][x + 1] = tmpColor;
			candyCheck(num);
			board[y][x + 1] = board[y][x];
			board[y][x] = tmpColor;
		}
	}

	for (int x = 0; x < num; x++) {
		for (int y = 0; y < num - 1; y++) {
			tmpColor = board[y][x];
			board[y][x] = board[y + 1][x];
			board[y + 1][x] = tmpColor;
			candyCheck(num);
			board[y + 1][x] = board[y][x];
			board[y][x] = tmpColor;
		}
	}

	cout << maxCandy;
}
