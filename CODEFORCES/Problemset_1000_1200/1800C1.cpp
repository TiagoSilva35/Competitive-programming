
#include <algorithm>
#include <bits/stdc++.h> 
#include <iterator>
#include <queue>

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

void solve(){
	ll n;
	cin >> n;
	vll v(n);
	forn(i,n){
		cin >> v[i];
	}
	ll ans = 0;
	priority_queue<int>mx;
	forn(i,n){
		mx.push(v[i]);
		if (!v[i]){ 
			auto temp = mx.top();
			ans += temp;
			mx.pop();

		}
	}
	cout << ans << endl;
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