#include<bits/stdc++.h>
using namespace std;
int main() {
        stack<char> s;
        string w = "Ha Noi";
        for(auto x: w)
                s.push(x);
        while(!s.empty()) {
                cout << s.top();
                s.pop();
        }
}