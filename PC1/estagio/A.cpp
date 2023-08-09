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
ll MOD = 998244353;
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
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())


void solve() {
    multimap<int, int> m;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        string str;
        int n, times;
        cin >> str;
        if (str == "ADD") {
            cin >> times >> n;
            for (int i = 0; i < times; i++) {
                m.insert({n, i});
            }
        } else if (str == "REM") {
            cin >> times >> n;
            auto range = m.equal_range(n);
            int count = 0;
            for (auto it = range.first; it != range.second && count < times; ++it) {
                m.erase(it); 
                count++;
            }
            if (count < times) {
                cout << "removal refused" << '\n';
            }
        } else {
            cin >> n;
            cout << m.count(n) << '\n';
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}