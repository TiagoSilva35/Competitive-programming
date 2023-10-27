
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

void solve(){
	ll n;
	cin >> n;
	ll a = n;
	int temp = 0;
	bool ans = true;
	do{
		//cout << n << endl;
		temp = n % 10;
		//cout << temp << " " << n << endl;	
		if (temp != 4 && temp != 7){
			ans = false;
		}
		n/=10;
	}while(n > 0); //447

	if (a % 7 == 0 || a % 4 == 0 || a % 47 == 0 || a % 74 == 0) ans = true;
	cout << (ans ? "YES" : "NO") << endl;
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