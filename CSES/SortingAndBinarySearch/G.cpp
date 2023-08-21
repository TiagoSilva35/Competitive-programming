
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

int n,x;

void solve(){
	cin >> n >> x;
	vpii v(n);
	forn(i,n){
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(all(v));
	int i = 0,j = n-1;
	bool flag = false;
	auto it = max_element(all(v),
			[](const pii &a,const pii &b){
				return a.first < b.first;
			});
	if((it -> first)*2 < x){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	while(i < n){
		if (i == j){
			j = n - 1;
			i++;
			continue;
		}
		if (v[i].first + v[j].first == x){
			cout << v[i].second + 1 << " " << v[j].second + 1 << endl;
			flag = true;
			break;
		}
		else j--;
	}
	if (!flag) cout << "IMPOSSIBLE" << endl;
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
