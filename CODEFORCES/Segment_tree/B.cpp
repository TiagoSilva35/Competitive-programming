
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long,long long> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<long long> vi;
typedef vector<vector<long long> > vv;
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
#define INF long long_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const long long mxN = 400001;
long long tree[mxN], a[mxN];

void build(long long lb, long long  rb, long long v){
    if (lb == rb){
        tree[v] = a[lb];
        return;
    }
    long long m = lb + (rb-lb)/2;
    build(lb, m, 2*v);
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
    if (l == lb && r == rb){
        return tree[v];
    }
    if (l > r) return 1e9;
    long long m = lb + (rb-lb)/2;
    return min(get_sum(lb, m, l, min(r, m), v*2), get_sum(m + 1, rb, max(l, m + 1), r, 2*v+1));
}

void update (long long v, long long lb, long long rb, long long pos, long long new_val){
    if (lb == rb) tree[v] = new_val;
    else{
        long long m = lb + (rb-lb)/2;
        if (pos <= m){
            update(2*v, lb, m, pos, new_val);
        }
        else
            update(2*v + 1, m + 1, rb, pos, new_val);
        tree[v] = min(tree[2*v] , tree[2*v + 1]);

    }

}

void solve(){
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; ++i){
        cin >> a[i];
    }
    memset(tree, 1e9+1, sizeof(long long)*4*n);
    build(0, n-1, 1);
    for (long long i = 0; i < m; ++i){
        long long type, b, c; cin >> type >> b >> c;
        if (type == 1){
            update(1, 0, n-1, b, c);
        }
        else{
            cout << get_sum(0, n-1, b, c-1, 1) << endl;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    for(long long it=1;it<=t;it++) {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}
