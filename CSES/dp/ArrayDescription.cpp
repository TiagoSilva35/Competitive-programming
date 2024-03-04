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
ll MOD = 1000000007;
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
#define INF INT_MAX
#define mod(x) ((x) % MOD)
#define modS(x) (((x % MOD) + MOD) % MOD)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(v) for(auto i:v) cout << i << " "; cout << ln;
#define printv(v) for(auto i:v) print(i);
#define debug(x) cout << #x << " = " << x << ln;
#define debugv(x) cout << #x << " = "; printv(x);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())

const int mxN = 1e5;
int n, m;
int x[mxN+1];
ll countAr(int idx){
    ll ans = 0;
    if (idx == n){
        return 1;
    }
    if (x[idx] == 0){
        int mi = min(x[idx+1], x[idx-1]);
        int mx = max(x[idx+1], x[idx-1]);
        if (mx - mi > 1) return 0;
        if (mi == mx){
            for (int i = mi - 1 != 0 ? mi - 1 : mi; i <= mx + 1; ++i){
                x[idx] = i;
                ans += countAr(idx + 1);
            }
        }
        else{
            x[idx] = mi + 1;
            ans += countAr(idx + 1);
        }
    }
    else
        ans += countAr(idx+1);
    return ans;
}

void solve(){
    cin >> n >> m;
    forn(i, n){cin >> x[i];}
    cout << countAr(0) << endl;
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