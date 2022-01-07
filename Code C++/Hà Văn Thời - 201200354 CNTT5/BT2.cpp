#include<bits/stdc++.h>

using namespace std;
void UocChung(int a){ 
    for(int i = 1; i <= a; i++)
        if(a % i == 0) 
            cout << i << " ";
}
int UCLN(int a, int b){
    if(a * b == 0) 
        return a + b;
    if(a > b) 
        return UCLN(a % b, b);
    return UCLN(a, b % a);
}
int main(){
    int x, y; 
    cout << "Nhap 2 so nguyen: "; cin >> x >> y;
    cout << "Uoc chung cua 2 so la: ";
    UocChung(UCLN(x, y));
}
