#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if (a == b) cout << c << endl;
    else if (b == c) cout << a << endl;
    else if (a == c) cout << b << endl;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        solve();
    }
}
