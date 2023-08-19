#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int m,n;
vector<pair<ll,pll>> v;
vi ans;
auto good(int x)->bool{
	ll sum = 0,temp,c;
	forn(i,n){
		temp = v[i].first * v[i].second.first + v[i].second.second;
		c = (x/temp)*v[i].second.first;
		temp = x%temp;
		c+= min(v[i].second.first,temp/v[i].first);
		sum += c;
		ans[i] = c;
	}
	return sum >= m;
}
void solve(){
	cin >> m >> n;
	v.resize(n);
	ans.resize(n);
	forn(i,n){
		ll t,z,y;
		cin >> t >> z >> y;
		v[i] = {t,{z,y}};
	}
	if (m == 0){
		cout << 0 << endl;
		for(auto j:ans){
			cout << j << " ";
		}
		cout << endl;
		return;
	}
	int l = 0 , r = 1e9;
	/* while(!good(r))r*=2; */
	while(r > l + 1){
		int m = l + (r-l)/2;
		if (good(m))r = m;
		else l = m;
	}
	cout << r << endl;
	for(auto i:ans){
		cout << i << " ";
	}
	cout << endl;

	
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
