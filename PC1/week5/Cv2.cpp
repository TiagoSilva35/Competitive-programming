#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<long long int> vi;
typedef vector<vector<long long int> > vv;
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
#define lli long long int 

vv memo(1010,vi(1010,0));

lli cc(int n, int target,vi v){
    for (int i = 0; i <= n; i++)
        memo[i][0] = 1;
    for(int i = 1; i <= target; i++)
        memo[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if(v[i-1] > j)memo[i][j] = memo[i-1][j];
            else memo[i][j] = memo[i-1][j] + memo[i][j-v[i-1]];
        }
        
    }
    return memo[n][target];
    
}

void solve(){
    int n,target;
    cin >> n >> target;
    vi v(n);
    forn(i,n){cin >> v[i];}
    cout << cc(n,target,v) << ln;

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