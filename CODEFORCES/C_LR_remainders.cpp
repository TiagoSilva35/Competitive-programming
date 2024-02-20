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
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
    
ll n, m;

ll getMid(ll s, ll e) {  return s + (e - s)/2;  }
    
ll getPdtUtil(ll *st, ll ss, ll se, ll qs, ll qe,
                                                ll si)
{
    if (qs <= ss && qe >= se)
        return st[si];
    if (se < qs || ss > qe)
        return 1;
    ll mid = getMid(ss, se);
    return (((getPdtUtil(st, ss, mid, qs, qe, 2*si+1)%m) *
            getPdtUtil(st, mid+1, se, qs, qe, 2*si+2) %m) % m);
}
ll getPdt(ll *st, ll n, ll qs, ll qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input";
        return -1;
    }
    
    return getPdtUtil(st, 0, n-1, qs, qe, 0);
}
ll constructSTUtil(ll arr[], ll ss, ll se,
                                ll *st, ll si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    ll mid = getMid(ss, se);
    st[si] =  (((constructSTUtil(arr, ss, mid, st, si*2+1) % m)*
                constructSTUtil(arr, mid+1, se, st, si*2+2) % m) % m);
    return st[si];
}
    
ll *constructST(ll arr[], ll n)
{
    ll x = (ll)(ceil(log2(n))); 
    ll max_size = 2*(ll)pow(2, x) - 1; 
    ll *st = new ll[4*n];

    constructSTUtil(arr, 0, n-1, st, 0);

    return st;
}
    
void solve(){
    cin >> n >> m;
    ll p = 1;
    ll v[n]; forn(i, n){cin >> v[i];p*=v[i];}
    string s; cin >> s;
    vll ans(n);
    ll lb = 0, rb = n-1;
    ll * tree = constructST(v, n);
    forn (i, n){
        ll p = getPdt(tree, n, lb, rb);
        ll remainder = p % m;
        ans[i] = remainder;
        if (s[i] == 'R'){
            rb--;
        }
        if (s[i] == 'L'){
            lb++;
        }
    }
    //cout << p % m;
    for (auto &i: ans)
        cout << " " << i;
    cout << endl;
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