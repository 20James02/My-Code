#include<bits/stdc++.h>
using namespace std;

void nhapDay(double *a, int &n){
    cout<< "Nhap so luong phan tu: ";
    cin>> n;

    for (int i=0; i<n; i++){
        cout<< "a[" << i << "] = ";
        cin>> a[i];
    }
}

void inDay(const double *a, const int &n){
    for (int i = 0; i < n; i++){
        cout<< a[i] << " ";
    }
}

double minOfArray(const double *a, const int &n){
    if (n == 2){
        return min(a[1], a[0]);
    }
    else if (n == 1){
        return a[0];
    }

    return min(a[n-1], minOfArray(a, n-1));
}

int main()
{
    int n;
    double a[100];
    nhapDay(a, n);
    inDay(a, n);
    cout<< endl;
	//
    cout<< "Gia tri nho nhat cua day so tren la: " << minOfArray(a, n);
    return 0;
}
