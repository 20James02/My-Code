#include <bits/stdc++.h>

using namespace std;
class DaThuc{
	private: 
		int n;
		double *a;
	public:
	DaThuc();
	void Nhap(){
	cout << "Nhap bac cua da thuc: ";
		cin >> n;
    a = new double[n + 1];
    for (int i = n; i >= 0; i--) {
        cout << "Nhap he so cua x^" << i << ": ";
        	cin >> a[i];
    	}
	}
	void Xuat(){
		cout << "Da thuc vua nhap la: y = ";
		for( int i = n; i >= 0; i--){
			cout << a[i]<<"x^"<< i;
			if(i != 0)
				cout << " + ";
		}
	}
	double TinhGT(double x, int i){
    	if (i==0)
       		 return a[0];
   		else	
        	return a[i]*pow(x, i) + TinhGT(x, i -1 );
	}
	void XuatGT(){
   		double x;
    	cout << "\nGia tri x = ";
    		cin >> x;
    	cout << "Gia tri cua da thuc voi x = " << x << " la: " << TinhGT(x, n);
	}
};
	DaThuc::DaThuc(){
    n = 0;
    a = new double;
	}
int main(){
	DaThuc DaThuc1;
	DaThuc1.Nhap();
	DaThuc1.Xuat();
	DaThuc1.XuatGT();
}