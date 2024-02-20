#include <bits/stdc++.h> 
        
using namespace std;
        
typedef long long ll;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()

        
void solve(){
    int n; cin >> n;
    set<int> s;
    forn(i ,n){
        int x; cin >> x;
        s.insert(x);
    }
    for (int i = 1; i <= n; ++i){
        if (s.find(i) == s.end()){
            cout << 2*i << endl;
            return;
        }
    }
    cout << *s.end() + 1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t = 1;
//	cin >> t;
        for(int it=1;it<=t;it++) {
            //cout << "Case #" << it+1 << ": ";
            solve();
        }
        return 0;
    }

