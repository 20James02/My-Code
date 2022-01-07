#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	pair<int, int> A[n+5];
	for(int i = 1; i <= n; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A+1, A+n+1);				//Sap xep tang dan theo first
	for (int i = 1; i <= n; i++) {
		cout << A[i].second << " ";
	}
}