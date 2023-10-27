
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll mdc(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll mmc(ll a, ll b){
	return (a*b)/mdc(a,b);
}

void solve(){
	ll n, x, y;
	cin >> n >> x >> y;
	ll both = n/mmc(x,y);	
	ll numx = n/x - both;
	ll numy = n/y - both;
	ll sumx = numx*(n + n - numx + 1)/2;
	ll sumy = numy*(numy + 1)/2;
	cout << sumx - sumy << endl;
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