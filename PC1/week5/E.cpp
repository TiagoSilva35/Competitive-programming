#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector <vector<lli>> DP(1001,vector<lli>(1001,0));

auto ks(int n, int W , vector<lli>v , vector <lli>w){
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
	int t;
	cin >> t;
    for (int x = 0; x < t; x++){   
        int n;
        cin >> n; 
        vector<lli>values(n+10);
        vector<lli>weights(n+10);
        for(int i = 0; i < n; i++){
            cin >> values[i] >> weights[i];
        }
        int T,value = 0;
        cin >> T;
        vector <lli> trucks(T);
        for (int i = 0; i < T; i++)
        {
            int C;
            cin >> C;
            trucks[i] = C;
        }
        ks(n,*max_element(trucks.begin(),trucks.end()),values,weights);
        for (int i = 0; i < T; i++)
        {
            value += DP[n][trucks[i]];
        }
        cout << value << endl;
    }
}