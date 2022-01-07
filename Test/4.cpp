#include<bits/stdc++.h>
using namespace std;

bool kqTim(const char *ptr, const char &c){
    if (*ptr=='\0'){
        return false;
    }
    else if (*ptr==c){
        return true;
    }

    return kqTim(ptr+1, c);
}

int main(){
    char s[100];
    cout<< "Nhap xau ki tu: ";
    cin.getline(s, 100);
	//
    char c;
    cout<< "Nhap chu cai can tim: ";
    cin>> c;
    cout<< endl;
	//
    if (kqTim(s, c) == true){
        cout<< "Tim thay chu cai "
            << "\'" << c << "\'"
            << " trong xau ki tu "
            << "\"" << s << "\"";
    }
    else{
        cout<< "Khong ton tai "
            << "\'" << c << "\'"
            << " trong xau ki tu "
            << "\"" << s << "\"";
    }
    return 0;
}
