#include<bits/stdc++.h>
using namespace std;

vector<int> obj; 
vector<vector<int>> loc; 
vector<vector<int>> dp;

int minLoc(int idx, int lastLoc) {
    if(idx == (int)obj.size()) return 0;
    
    if(dp[idx][lastLoc+1] != -1) return dp[idx][lastLoc+1];
    
    int ans = INT_MAX;
    
    for(int i=0; i<(int)loc.size(); i++) {
        if(find(loc[i].begin(), loc[i].end(), obj[idx]) != loc[i].end()) {
            int temp = (i == lastLoc ? 0 : 1) + minLoc(idx+1, i);
            ans = min(ans, temp);
        }
    }
    
    return dp[idx][lastLoc+1] = ans;
}

int main() {
    int T; cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;
        obj = vector<int>(N);
        loc = vector<vector<int>>(M);
        dp = vector<vector<int>>(N, vector<int>(M+1, -1)); 
        
        for(int i=0; i<N; i++) cin >> obj[i];
        for(int i=0; i<M; i++) {
            int O; cin >> O;
            loc[i] = vector<int>(O);
            for(int j=0; j<O; j++) cin >> loc[i][j];
        }
        
        int ans = minLoc(0, -1);
        cout << ans << endl;
    }
    return 0;
}







