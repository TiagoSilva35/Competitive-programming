#include <stack>
#include <iostream>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve(){
	int n, h;cin >> n >> h;
	map<int, vector<char>> mp;
	int k = 0;
	for(int i = 0; i < h; ++i){
		k = 0;
		while(k < n + 1){
			char c;cin >> c;
			if (c == '|')k++;
			else{
				mp[k-1].pb(c);
			}
		}
	}
	int q;cin >> q;
	map<int, stack<char>>m2;
	forn(i, q){
		string m;int b;int t;cin >> m >> b >> t;
		char temp = mp[b - 1][0];mp[b-1].erase(mp[b-1].begin());
		cout << temp << endl;
		m2[t-1].push(temp);

	}
	string ans = "";
	forn(i, n){
		if (!m2[i].empty()){ans+=m2[i].top();}
		else{
			if (!mp[i].empty())
				ans+=mp[i][0];
		}
	}
	cout << ans << endl;
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
