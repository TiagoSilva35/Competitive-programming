
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
	int n,x1,y1,x2,y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	if (n == 1){
		cout << 0 << endl;
		return;
	}
	else if (n == 2){
		cout << 0 << endl;
		return;
	}
	if (x1 == x2 || y1 == y2){
		int pt1 = min(x1,y1);
		int pt2 = min(y2,x2);
		cout << abs(pt2-pt1) << endl;
	}
	else{
			int a = (x1 < n/2 && y1 < n/2)?min(x1,y1):n-max(x1,y1)+1;
			int b = (x2 < n/2 && y2 < n/2)?min(x2,y2):n-max(x2,y2)+1;
			if (a != b){
				cout << abs(b-a) << endl;
			}
			else
				cout << 0 << endl;
	}
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
