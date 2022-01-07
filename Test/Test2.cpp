#include <iostream> 
using namespace std; 
int main() {
	int n;
	cout<<"Nhap so phan tu: "<< endl;
	cin >> n;
	float a[n];
	cout<<"Nhap day: ";
	for(int i=0; i<n; i++) {
		cin>> a[i];
	}
	for(int i=0; i<n; i++) {
		if(a[i] > 0)
			cout << a[i] <<" ";
	}
	cout<< endl;
	for(int i=0; i<n; i++) {
		if(a[i] < 0)
			cout << a[i] << " ";
	}
    system("pause");
return 0;
}