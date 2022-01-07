#include <bits/stdc++.h>

using namespace std;
float Sum(int n) {
	float S = 0;
	for (int i = 1; i <= n; i++)
		S += 1/i;
	return S;
}


int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "S(" << n << ") = " << Sum(n);
	return 0;
}