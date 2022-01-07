#include <iostream>
using namespace std;

int main() {
	int n;
	cout <<"Nhap n: ";
	cin >> n;
	int a[n];
	cout <<"\nNhap day so nguyen: ";
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] % 2 == 0 && a[i] > 0) {
			cout <<"\nEVEN POSITIVE";
		}
		 if (a[i] % 2 == 0 && a[i] < 0) {
			cout <<"\nEVEN NEGATIVE";
		}
		if (a[i] % 2 == 1 && a[i] > 0) {
			cout <<"\nODD POSITIVE";
		}
		if (a[i] % 2 == 1 && a[i] < 0) {
			cout <<"\nODD NEGATIVE";
		}
		if (a[i] == 0) {
			cout <<"\nNULL";
		}
	}
	return 0;

}