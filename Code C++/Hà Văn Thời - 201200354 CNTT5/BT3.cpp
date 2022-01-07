#include <bits/stdc++.h>

using namespace std;
class Ds{
private:
    int n;
    double *a;
public:
    Ds(int);
    void Nhap() {
        a = new double[n + 1];
        for (int i = 1; i <= n; i++) {
            cout << "Nhap so thu " << i << " : ";
        	   cin >> a[i];
    	}
	}
    void Xuat() {
        cout << "Day so vua nhap la: ";
        for (int i = 1; i <= n; i++) {
            cout << a[i] << "  ";
    	}
	}
    double Min(int i) {
        if (i == 1)
            return a[1];
        else
            return min(a[i], Min(i-1));
	}
};
	Ds::Ds(int x) {
	   n = x;
	   a = new double [n];
    }
int main(){
	int x;
	cout << "Nhap so phan tu: ";
		cin >> x;
	if (x == 0)
		cout << "NULL";
	else {
        Ds Ds1(x);
        Ds1.Nhap();
        Ds1.Xuat();
        cout << "\nGia tri nho nhat day so la: " << Ds1.Min(x-1);
    }
}
