#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector <vector<lli>> memo(1001,vector<lli>(1001,0));

auto lcs(string a, string b, int n , int m){
    for(int i = 0; i <= n ; i++){
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j== 0)
                memo[i][j] = 0;

            else if (a[i-1] == b[j-1]){
                memo[i][j] = memo[i-1][j-1] + 1;
            }
            else{
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
            }
        }
    }
    
    return memo[n][m];
}


int main(){
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    cout << lcs(a,b,n,m) << endl;

}