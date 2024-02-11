
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

const long long mxN = 400001;
long long tree[mxN], a[mxN];
int cur_idx = 0;

void build(int t, long long lb, long long  rb, long long v){
    cur_idx++;
    if (lb == rb){
        tree[v] = a[lb];
        return;
    }
    long long m = lb + (rb-lb)/2;
    build(t^1, lb, m, 2*v);
    build(t^1, m+1, rb, 2*v + 1);
    if (!t) tree[v] = tree[2*v] ^ tree[2*v+1];
    else tree[v] = tree[2*v] | tree[2*v+1];

}

void update (int t, long long v, long long lb, long long rb, long long pos, long long new_val){
    cur_idx++;
    if (lb == rb) tree[v] = new_val;
    else{
        long long m = lb + (rb-lb)/2;
        if (pos <= m){
            update(t^1, 2*v, lb, m, pos, new_val);
        }
        else
            update(t^1, 2*v + 1, m + 1, rb, pos, new_val);
        if (!t) tree[v] = tree[2*v] ^ tree[2*v + 1];
        else tree[v] = tree[2*v] | tree[2*v + 1];

    }

}

void solve(){
    int n,m;cin >> n >> m;
    for (int i = 0; i < (1 << n); ++i){
        cin >> a[i];
    }
    build(n&1, 0, (1 << n)-1, 1);
    cur_idx = 0;
    for (int i = 0; i < m; ++i){
        int p, b;
        cin >> p >> b;p--;
        update (n&1,1, 0, (1 << n)-1, p ,b);
        cout << tree[1] << endl;
    }

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
