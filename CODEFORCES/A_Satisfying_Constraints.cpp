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
    int n; cin >> n;
    ll lb = 0;
    ll rb = 1e10;
    vll not_equalv;
    ll not_equal = 0;
    forn(i ,n){
        int a, x;
        cin >> a >> x;
        if (a == 1){
            lb = max(lb, (ll)x);
        }
        else if (a == 3) not_equalv.push_back(x);
        else if(a == 2) rb = min(rb, (ll)x);
    }
    if (rb < lb){
        cout << 0 << endl;
        return;
    }
    for (auto &i: not_equalv){
        if (i >= lb && i <= rb) not_equal++;
    }
    //cout << lb << " " << rb << endl;
    cout << abs(rb - lb) + 1 - not_equal << endl;

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