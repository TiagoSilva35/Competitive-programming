#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector<vector<lli>>memo(1001,vector <lli>(1001,0));

auto cc(vector<int>values,int m,int N){
    for (int i = 0; i <= m; i++)
        memo[i][0] = 1;
    for (int j = 1; j <= N; j++)
        memo[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if(values[i] > j)
                memo[i][j] = memo[i-1][j];
            else
                memo[i][j] = memo[i-1][j] + memo[i][j-values[i]];
        }
        
    }
    return memo[m][N];
}

int main(){
    int m,N;
    cin >> m >> N;
    vector <int> values(m+1,0);
    for (int i = 1; i <= m; i++)
    {
        cin >> values[i];
    }
    cout << cc(values,m,N) << endl;
}