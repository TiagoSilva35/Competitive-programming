#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool isPerfect(ll n) {
    ll sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}


void solve(){
    int n;cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; ++i){int a;cin >> a;sum+=a;}
    cout << (isPerfect(sum) ? "YES" : "NO") << endl;;

}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        solve();
    }
}
