#include <iostream>
#include <iomanip>

using namespace std;

int fib(int k){
        if(k==1)
                return 1;
        if(k==2)
                return 1;
        if(k>2)
                return fib(k-1)+fib(k-2);
}
int main(){
        int n, s[100];
        s[0]=1;
        s[1]=1;
        cin>>n;
        for(int i=2; i<n; i++){
                s[i]=s[i-2]+s[i-1];
        cout<< setw(5)<< s[i] << endl;
        }
}