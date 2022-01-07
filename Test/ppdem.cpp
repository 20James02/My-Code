#include <iostream> 
using namespace std;

int main() {
	int sum = 0;
	int count = 0;
	for (int i = 6; i <= 14; i++) {
		for (int j = 0; j <= 8; j++) {
			for (int k = 0; k <= 8; k++) {
				sum = i + j + k;
				if (sum <= 14) {
					count++;
				}
			}

		}
	}
	cout << count;
	system("pause");
	return 0;
}