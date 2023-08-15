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

int ANS = INF;

int rec(vi v,int m, int d,int n,int idx,int time,int total){
	if (idx == n){
		ANS = min(ANS,total);
		return 0;
	}
	for(int i = idx; i < n;i++){
		if ((find(all(v),i+1) != v.end()) || (time == d)){
			time = 0;
			ANS += rec(v,m,d,n,idx+1,time + 1,total+1);
		}
	}
	return ANS;
}

void solve(){
	int n,m,d;
	cin >> n >> m >> d;
	vi v(n);
	ANS = INF;
	forn(i,m){cin >> v[i];}
	cout << rec(v,m,d,n,0,0,0) << endl;

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
