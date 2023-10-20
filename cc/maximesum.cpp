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
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    int n;
    cin >> n;
    vi v(n);
    forn(i, n){
        cin >> v[i];
    }
    vi prefix_sum(n);
    vi sufix_sum(n);

    prefix_sum[0] = v[0];
    sufix_sum[n-1] = v[n-1];

    for(int i = 1; i < n; i++){
        prefix_sum[i] = max(prefix_sum[i-1],v[i]);
        sufix_sum[n-i-1] = max(sufix_sum[n-i], v[n-i-1]);
    }
    int ans = 0;
    forn(i, n-2){
        ans = max(ans, prefix_sum[i] + sufix_sum[i+1]);
    }
    cout << v[0] + ans + v[n-1] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}