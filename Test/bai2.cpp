#include<bits/stdc++.h>

using namespace std;
void uoc(int a){ 
	for(int i=1; i<=a; i++){
		if(a%i==0) cout << i << " ";
	}
}
int ucln(int a, int b){
	if(a*b==0) return a+b;
	if(a>b) return ucln(a%b, b);
	return ucln(a, b%a);
}
int main(){
	int a, b; 
	cout << "Nhap 2 so: "; cin >> a >> b;
	cout << "Cac uoc cua 2 so la: ";
	uoc(ucln(a, b));
}
