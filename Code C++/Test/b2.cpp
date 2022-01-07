#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int S = 0;
	for (int i = 1; i <= n; i++)
		S += pow(i,2);
	cout << "S(" << n << ") = " << S;
	return 0;
}