#include<bits/stdc++.h>

using namespace std;
double mu(double x, int y){
	if(y==0) return 1;
	double a=mu(x, y/2);
	if(y%2==0) return a*a;
	if(y%2!=0) return x*a*a;
}
double daThuc(double a[], int n, double x){
	if(n==0) return a[0];
	return a[n]*mu(x, n)+daThuc(a, n-1, x);
}
int main(){
	double a[100], x;
	int n;
	cout << "Nhap bac cua da thuc: "; cin >> n;
	cout << "Nhap he so da thuc: ";
	for(int i=0; i<=n; i++){
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	cout <<"Nhap x: "; cin >> x; 
	cout << "Ket qua cua da thuc tai x la: " << daThuc(a, n, x);
}

