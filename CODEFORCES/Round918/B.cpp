#include <bits/stdc++.h>

using namespace std;

void solve(){
    vector<string> v(3);
    for (int i = 0; i < 3; ++i){
        cin >> v[i];
    }
    for (int i = 0; i < 3 ; ++i){
        bool a = false, b = false, c = false;
        for (auto k: v[i]){
            if (k == 'A') a = true;
            if (k == 'B') b = true;
            if (k == 'C') c = true;

        }
        if (!a){ cout << 'A' << endl;return;}
        if (!b){ cout << 'B' << endl;return;}
        if (!c){ cout << 'C' << endl;return;}
    }
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        solve();
    }
}
