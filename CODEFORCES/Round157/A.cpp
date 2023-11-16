#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

ll MOD = 1000000007;
double eps = 1e-12;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve(){
	int x, y, k;
	cin >> x >> y >> k;
	if (x < y){
		if (abs(x-y) <= k){
			cout << y << endl;
			return;
		}
		cout << x + k + 2*(y - (x + k)) << endl;
	}
	else{
		cout << x << endl;
		return;
	}

}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t = 1;
	cin >> t;
	for (int it = 1; it <= t; it++){
		//cout << "Case #" << it + 1 << ": ";
		solve();
	}
	return 0;
}
