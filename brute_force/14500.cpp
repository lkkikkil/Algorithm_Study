#include <iostream>

using namespace std;

int board[501][501];

pair<int, int> tetromino[19][4]{
	{{0,0}, {0,1}, {1,1},{1,0}},

	{{0,0}, {0,1}, {0,2},{0,3}},
	{{0,0}, {1,0}, {2,0},{3,0}},

	{{0,0}, {1,0}, {2,0},{2,1}},
	{{0,1}, {1,1}, {2,1},{2,0}},
	{{0,0}, {1,0}, {2,0},{0,1}},
	{{0,0}, {0,1}, {1,1},{2,1}},
	{{0,0}, {1,0}, {1,1},{1,2}}, 
	{{0,2}, {1,2}, {1,1},{1,0}},
	{{0,0}, {0,1}, {0,2},{1,0}},
	{{0,0}, {0,1}, {0,2},{1,2}},

	{{0,0}, {1,0}, {1,1},{2,1}},
	{{0,1}, {1,1}, {1,0},{2,0}},
	{{0,0}, {0,1}, {1,1},{1,2}},
	{{0,1}, {1,1}, {1,0},{0,2}},

	{{0,0}, {0,1}, {0,2},{1,1}},
	{{0,1}, {1,0}, {1,1},{1,2}},
	{{0,0}, {1,0}, {1,1},{2,0}},
	{{1,0}, {0,1}, {1,1},{2,1}},
};

int main() {	
	int row, col;
	cin >> row >> col;

	for (int rowCount = 0; rowCount < row; rowCount++) {
		for (int colCount = 0; colCount < col; colCount++) {
			cin >> board[rowCount][colCount];
		}
	}

	int maxScore = 0;
	for (int rowCount = 0; rowCount < row; rowCount++) {
		for (int colCount = 0; colCount < col; colCount++) {
			for (int blockCount = 0; blockCount < 19; blockCount++) {
				int sum = 0;
				for (int posCount = 0; posCount < 4; posCount++) {
					int curRow = rowCount + tetromino[blockCount][posCount].first;
					int curCol = colCount + tetromino[blockCount][posCount].second;
					if (curRow < row && curCol < col) {
						sum += board[curRow][curCol];
					}
				}
				if (sum > maxScore) {
					maxScore = sum;
				}
			}
		}
	}

	cout << maxScore;

	return 0;
}
