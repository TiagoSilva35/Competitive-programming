
#include <bits/stdc++.h> 
#include <ostream>

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

bool compare(pll a, pll b){
	return  a.second < b.second;
}

void solve(){
	ll n;
	cin >> n;
	ll ans = 1;
	vpll v(n);
	forn(i,n){
		cin >> v[i].first >> v[i].second;
	}
	sort(all(v),compare);
	//for(auto pair: v){
	//	cout << pair.first << " " << pair.second << endl;
	//}
	ll r = v[0].second;
	for(int i = 1; i < n; i++){
		if(r <= v[i].first){
			ans++;
			//l = v[i].first;
			r = v[i].second;
		}
	}
	cout << ans << endl;
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