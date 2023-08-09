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

int ANS = 0;
bool flag = false;
vv memo(4001,vi(4001,-1));

int rec(vi &v,int n,int idx,int c){
    if (n == 0){
        flag = true;
        ANS = max(ANS,c);
        return 1;
    }
    if (n < 0)
        return 0;

    if (memo[idx][n] != -1)
        return memo[idx][n];

    for (int i = idx; i < 3; i++)
    {
        memo[idx][n] = rec(v,n-v[i],i,c+1);
        if (flag){
            flag = false;
            c = 0;
        }
    }
    return c;
    
}

void solve(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vi v = {a,b,c};
    int counter = 0;
    sort(all(v));
    rec(v,n,0,counter);
    cout << ANS << endl;

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