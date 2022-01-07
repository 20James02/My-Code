#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;
    bool b[1001];
    int a[1001];
    int n, k;
    cin >>n;
    for (int  i = 0; i < 1001; i++){
        b[i] = false;
    }
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    for (int i = 0; i < n; i++)
    if (!b[a[i]]){
        if (q.size() < k){
            b[a[i]] = true;
            q.push(a[i]);
        }
        else{
            b[q.front()] = false;
            b[a[i]] = true;
            q.push(a[i]);
            q.pop();
        }
    }
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}