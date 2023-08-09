#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector <lli> DP(10001);

void p(vector <lli>v,int n){
    DP[1] = v[0];
    for (int i = 2; i <= n; i++)
    {
        DP[i] = DP[i-1] + v[i-1];
    }
}

int main(){
    int n;
    cin >> n;
    vector<lli>v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    p(v,n);
    /*for (int i = 1; i <= n; i++)
    {   
        cout << DP[i] << endl;
    }
    */
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        lli a,b;
        cin >> a >> b;
        cout << DP[b+1] - DP[a] << endl;
    }
    


}