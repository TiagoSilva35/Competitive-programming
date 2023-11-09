
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
typedef vector<vector<ll>> vvll;
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

ll n = 0;
vector<vector<ll>> dp(501,vll(500*501/4 + 501 ,-1));

ll rec(vll &v, ll target, ll sum, vector<bool> &visited, ll idx){
	if (dp[idx][sum] != -1) return dp[idx][sum];
	if (sum == target) return 1;
	if (sum > target || idx >= sz(v)) return 0;
	dp[idx][sum] = rec(v, target, sum, visited, idx + 1) % MOD + rec(v, target, sum + v[idx], visited, idx + 1) % MOD;
	return dp[idx][sum];
}
void solve(){
	cin >> n;
	vll v(n);
	ll sum = 0;
	forn(i,n){
		v[i] = i + 1;
		sum += i + 1;
	}
	if (sum % 2 != 0){
		cout << 0 << endl;
		return;
	}
	vector<bool> visited(n,false);
	cout << rec(v, sum/2, 0, visited, 0)/2 << endl;	
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
