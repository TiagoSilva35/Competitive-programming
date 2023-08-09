#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector<vector<lli>>DP(1100,vector<lli>(1100,0));

lli c(vector<vector<char>>grid, int n){
    if (grid[n-1][n-1] == '*' || grid[0][0] == '*')
        return 0;
    else{
        DP[n-1][n-1] = 1;
        for (int i = n-2 ; i >= 0; i--){
            if (grid[i][n-1] == '*')
                DP[i][n-1] = 0;
            else
                DP[i][n-1] = (DP[i+1][n-1] + DP[i][n])% 1000000007;
        }
        for(int j = n-2 ; j >= 0; j--){
            if (grid[n-1][j] == '*')
                DP[n-1][j] = 0;
            else
                DP[n-1][j] = (DP[n][j] + DP[n-1][j+1])% 1000000007;
        }
        for(int i = n-2 ; i >= 0; i--){
            for(int j = n-2 ; j >= 0; j--){
                if (grid[i][j] == '*')
                    DP[i][j] = 0;
                else
                    DP[i][j] = (DP[i+1][j] + DP[i][j+1])% 1000000007;
            }
        }
        
    }
    return DP[0][0];
}

int main(){
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin >> grid[i][j];

        }
    }
    cout << c(grid , n) << endl;
}