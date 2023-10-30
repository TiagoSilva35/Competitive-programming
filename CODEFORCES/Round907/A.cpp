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

void solve(){
	int n;
	cin >> n;
	vi v(n);
	forn(i,n){
		cin >> v[i];
	}

	for(int i = 2; i < n - 1; i++){
		if (v[i] <= v[i+1]){
			continue;
		}
		else{
			if ((i + 1) & 1 && v[i] > v[i+1]){
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
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