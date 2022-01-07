#include <bits/stdc++.h>

using namespace std;
void Nhap(string &a, char &b){
    cout << "Nhap tu bat ki: ";
    cin >> a;
    cout << "Nhap ki tu muon tim kiem: ";
    cin >> b;
}
bool Tim(string &a, char &b, int n){
    if (n < 0)    
		return false;
    else if (a[n] == b)   
		return true;
    else
        return (Tim(a, b, n - 1));
}
int main() {
    string a;
    char b;
    Nhap(a, b);
    bool value = Tim(a, b, a.size() - 1);
    if (value)
        cout << "Ki tu " << b << " co trong xau.";
    else
        cout << "Ki tu " << b << " khong co trong xau.";
}
