#include <iostream> 
using namespace std;

int main() {
	int n;
	cout <<"Nhap so phan tu: ";
	cin >> n;
	int a[n], b[n+1];
	cout << "\nNhap mang so nguyen: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int  k, x;
	cout << "\nNhap vi tri can chen: ";
	cin >> k;
	cout <<"\nNhap so can chen: ";
	cin >> x;
	for (int i = 0; i < k; i++) {
		if (i == (k-1)) {
			b[i] = x;
		} else {
			b[i] = a[i];
		}
	}
	for (int i = n; i >= k; i--) {
		b[i] = a[i-1];
	}
	cout <<"\nMang sau khi chen la: ";
	for (int i = 0; i <= n; i++) {
		cout << b[i] <<" ";
	}
	return 0;
}