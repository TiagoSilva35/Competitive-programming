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
 
bool ans[26];

void solve() {
	string s;
	cin >> s;
	
	memset(ans, 0, sizeof(ans));
	
	for (int i = 0; i < (int)s.size(); i++) {
		int j = i;
		while (j + 1 < (int)s.size() && s[j + 1] == s[i])
			j++;
		if ((j - i) % 2 == 0)
			ans[s[i] - 'a'] = true;
		i = j;
	}
	
	for (int i = 0; i < 26; i++) if (ans[i])
		cout << char('a' + i);
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