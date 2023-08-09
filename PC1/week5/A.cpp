#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector <lli>DP(100,-1);

lli fib(int n){
	DP[0] = 0;
	DP[1] = 1;
	for (int i = 2; i <= n; i++){
		DP[i] = DP[i-1] + DP[i-2];
	}
	return DP[n];
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n;
		cin >> n;
		cout << fib(n) << endl;
	}
}
