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
vector <bool> check(21,false);
bool ss(int n, int target, vi v,int idx){
    if (target == 0){
        return true;
    }
    if (target < 0){
        return false;
    }
    if (idx == n)
        return ss(n,target + v[idx],v,idx+1);

    for (int i = idx; i < n; i++)
    {
        if (!check[i]){
            check[i] = true;
            bool ANS = ss(n,target-v[i],v,i);
            check[i] = false;
            if (ANS)
                return ANS;
        }
    }
    return false;
}

void solve(){
    int n,x;
    cin >> n >> x;
    vi v(n);
    forn(i,n){cin >> v[i];}
    if (ss(n,x,v,0))
        cout << "YES\n";
    else
        cout << "NO\n";
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