#include <algorithm>
#include <bits/stdc++.h> 
#include <cmath>
#include <iomanip>

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

ll n,k;
ld sum;

auto good(ld x,vi v)->bool{
	sum = 0;
	forn(i,(int)v.size()){
		sum += floor(v[i]/x);	
	}
	return sum >= k;

}

void solve(){
	cin >> n >> k;
	vi v(n);
	forn(i,n){cin >> v[i];}
	//sort(all(v));
	ld l = 0, r = 1e8;
	for(ll i = 0; i < 100 ; i++){
		ld m = (r+l)/2;
		if(good(m,v)){
			l = m;		
		}
		else {
			r = m;
		}
	}
	cout << setprecision(20) << l << endl;
	
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
