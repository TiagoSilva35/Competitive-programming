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

int ks(vi values, vi weights , int W){
    for(int i = 1 ; i <= (int)values.size() ; i++){
        for(int j = 1 ; j <= W ; j++){
            if(weights[i-1] > j){
                memo[i][j] = memo[i-1][j];
            }
            else{
                memo[i][j] = max(memo[i-1][j],values[i-1]+memo[i-1][j-weights[i-1]]);
            }
        }
    }
    return memo[(int)values.size()][W];
}

void solve(){
    int n,W;
    cin >> n >> W;
    vi values(n);
    vi weights(n);
    forn(i,n){cin >> values[i] >> weights[i];}
    for (int i = 0; i <= n; i++)
    {
        memo[i][0] = 0; 
    }
    for (int j = 1; j <= W; j++)
    {
        memo[0][j] = 0;
    }
    cout << ks(values,weights,W) << ln;

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