#include <iostream>
#include <algorithm>

using namespace std;

int dwarfHeight[9];

int main()
{
	int sum = 0;
	for (int dwarfCount = 0; dwarfCount < 9; dwarfCount++) {
		int height;
		cin >> height;
		sum += height;
		dwarfHeight[dwarfCount] = height;
	}
	sort(dwarfHeight, dwarfHeight + 9);

	for (int one = 0; one < 8; one++) {
		for (int two = one + 1; two < 9; two++) {
			if (sum - dwarfHeight[one] - dwarfHeight[two] == 100) {
				for (int dwarfCount = 0; dwarfCount < 9; dwarfCount++) {
					if (dwarfCount != one && dwarfCount != two) {
						cout << dwarfHeight[dwarfCount] << "\n";
					}
				}
				return 0;
			}
		}
	}

	return 0;
}
