
#include <algorithm>
#include <bits/stdc++.h> 
#include <functional>

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
	map<int,int> mp;
	vi v(n);
	forn(i,n){
		int a;
		cin >> a;
		v[i] = a;
		mp[a]++;
	}
	if ((int)mp.size() >= 3){
		cout << "No" << endl;
	}
	else{
		if ((int)mp.size() == 1){
			cout << "Yes" << endl;
		}
		else{
			for (auto v : mp){
				if (v.second == n/2){
					cout << "Yes" << endl;
					return;
				}
			}
			cout << "No" << endl;
		}
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