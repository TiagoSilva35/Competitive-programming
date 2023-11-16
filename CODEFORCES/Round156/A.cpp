
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
	ll n;
	cin >> n;
	ll dif = n % 3;
	if (dif == 0){
		if (n - 1 - 4 < 0 || (n - 1 - 4 == 4 || n - 1 - 4 == 1)){
			cout << "NO" << endl;
			return;
		}
		cout << "YES" << endl;
		cout << 1 << " " << 4 << " " << n - 1 - 4;
	}
	else if (dif == 1 || dif == 2){
		if (n - 1 - 2 < 0 || (n - 1 - 2 == 2 || n - 1 - 2 == 1)){
			cout << "NO" << endl;
			return;
		}
		cout << "YES" << endl;
		cout << 1 << " " << 2 << " " << n - 1 - 2;
	}
	cout << endl;


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