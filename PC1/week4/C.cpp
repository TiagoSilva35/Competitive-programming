#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector <vector<lli>>memo(1001,vector<lli>(1001,-1));

lli change(int idx,int N, vector <int> val){
    if (N == 0){
        memo[idx][N] = 1;
        return 1;
    }
    if (N < 0 || idx < 0){
        return 0;
    }
    if(memo[idx][N] > -1){
        return memo[idx][N];
    }
    if(val[idx] > N){
        memo[idx][N] = change(idx-1,N,val);
    }
    else
        memo[idx][N] = change(idx,N-val[idx],val) + change(idx-1,N,val);
    return memo[idx][N];
}


int main(){
    int m,N;
    cin >> m >> N;
    vector <int> val(m);
    for (int i = 0; i < m; i++)
    {
        cin >> val[i];
    }
    cout << change(m-1,N,val) << endl;
    
}