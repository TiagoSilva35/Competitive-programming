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

vv memo(1001,vi(1001,-1));

int rec(string a , string b , int a_idx , int b_idx){
    if ((int)a.size() == a_idx || (int)b.size() == b_idx){
        return 0;
    }
    if (a[a_idx] == b[b_idx]){
        memo[a_idx][b_idx] = 1 + rec(a,b,a_idx+1,b_idx+1);
    }
    if (memo[a_idx][b_idx] != -1){
        return memo[a_idx][b_idx];
    }
    memo[a_idx][b_idx] = max(rec(a,b,a_idx + 1,b_idx),rec(a,b,a_idx,b_idx+1));
    return memo[a_idx][b_idx];
}

void solve(){
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    cout << rec(a,b,0,0) << ln;

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}