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
 
int rec(vi a, int n ,int maxi , int mini){
    if ((find(all(a),maxi) == a.end()) && (find(all(a),mini) == a.end())){
        return 1;
    }
    int ANS = 0;
    forn(i,n){
        vi temp_a1,temp_a2;
        temp_a1 = a;
        temp_a2 = a;
        temp_a1.erase(temp_a1.begin());
        temp_a2.pop_back();
        ANS += min(rec(temp_a1,n-1,maxi,mini),rec(temp_a2,n-1,maxi,mini));
    }
    return ANS;
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    forn(i,n){cin >> a[i];}
    int maxi = *max_element(all(a));
    int mini = *min_element(all(a));
    cout << rec(a,n,maxi,mini) << ln;
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
