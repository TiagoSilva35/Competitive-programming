#include <algorithm>
#include <bits/stdc++.h> 
#include <cctype>
#include <ios>
#include <iterator>
#include <utility>

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
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	n = 26;
	int ans = 0;
	vi lower(n,0), upper(n,0);
	for(auto i:s){
		if (islower(i)) lower[i - 'a']++;
		else upper[i - 'A']++;
	}
	forn(i,n){
		int pairs = min(lower[i],upper[i]);
		ans += pairs;
		lower[i] -= pairs;
		upper[i] -= pairs;
		int add = min(k, max(lower[i], upper[i])/2);
		k -= add; ans += add;
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