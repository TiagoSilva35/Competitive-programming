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
    vector<int> v(n);
    forn(i,n){cin >> v[i];}
    int num_operations = 0;
    int max_ele = *max_element(all(v));
    auto ptr = max_element(all(v));
    vpii pares;
    while (max_ele > v[n-1]){
        v[n-1]+=max_ele;
        num_operations++;
        pares.push_back({n-1,ptr-v.begin()});
    }
    forn(i,n-1){
        if (v[i] > v[i+1]){
            while (v[i] > v[i+1] + v[n-1]){
                v[n-1] += v[n-1];
                num_operations++;
                pares.push_back({n-1,n-1});
            }
            v[i+1] += v[n-1];
            pares.push_back({i+1,n-1});
            num_operations++;
        }
    }
    cout << num_operations << endl;
    for(auto&i:pares){
        cout << i.first + 1 << " " << i.second + 1 << endl;
    }
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