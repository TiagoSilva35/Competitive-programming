
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

ll sum_digits(ll x){
	ll sum = 0;
	while (x > 0){
		sum += x % 10;
		x /= 10;
	}
	return sum;
} 

void solve(){
	ll x,k;
	cin >> x >> k;
	ll sum = sum_digits(x);
	if (sum % k == 0){
		cout << x << endl;
		return;
	}
	else{
		while((sum_digits(x) % k != 0))
			x++;
	}
	cout << x << endl;
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