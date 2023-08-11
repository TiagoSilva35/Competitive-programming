#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

/*12:
12
21

1234:
1234
1243
1324
1342
1432
1423
*/

void rec(vi &perm,vi &v,vector<bool>&check){
    if((int)perm.size() == (int)v.size()){
        cout << perm[0];
        for (int i = 1; i < (int)v.size(); i++)
        {
            cout << " " << perm[i];
        }
        cout << ln;
    }
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (!check[i]){
            perm.pb(v[i]);
            check[i] = true;
            rec(perm,v,check);
            perm.pop_back();
            check[i] = false;
        }
    }
    return;
    
}

void solve(){
    int n;
    cin >> n;
    vi v(n);
    int counter = 1;
    for(int i = 0; i < n ; i++){cin >> v[i];if(i>0)counter*=i;};
    sort(all(v));
    vector<bool>check(n,0);
    vi perm;
    cout << counter*n << ln;
    rec(perm,v,check);

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}