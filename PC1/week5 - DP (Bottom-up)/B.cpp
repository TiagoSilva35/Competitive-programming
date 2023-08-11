#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector <vector<lli>> DP(1001,vector<lli>(1001,-1));

auto ks(int n, int W , vector<lli>v , vector <lli>w){
	for(int i = 0 ; i <= n ; i++)
		DP[i][0] = 0;
	for(int j = 1; j <= W; j++)
		DP[0][j] = 0;
	for (int i = 1; i <= n ; i++){
		for(int j = 1; j <= W ; j++){
			if (w[i-1] > j){
				DP[i][j] = DP[i-1][j];
			}
			else{
				DP[i][j] = max(DP[i-1][j],v[i-1] + DP[i-1][j-w[i-1]]);
			}
		}
	}
	return DP[n][W];
}


int main(){
	int n,W;
	cin >> n >> W;
	vector<lli>values(n+10);
	vector<lli>weights(n+10);
	for(int i = 0; i < n; i++){
		cin >> values[i] >> weights[i];
	}
	cout << ks(n,W,values,weights) << endl;
}
