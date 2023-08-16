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
	int n,k;
	cin >> n >> k;
	vi v(n);
	forn(i,n){cin >> v[i];}
	while(k--){
		/* cout << k << endl; */
		int x;cin >> x;
		int lb = 0, rb = n;
		int mb = 0;
		while(abs(rb-lb) != 1 && v[mb] != x){
			/* cout << lb << rb << endl; */
			/* cout << mb << endl; */
			mb = (lb+rb)/2;
			if (v[mb] > x){
				rb = mb;
			}
			else
				lb = mb;
		}
		if (v[mb] == x)cout << "YES" << endl;
		else cout << "NO" << endl;
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
