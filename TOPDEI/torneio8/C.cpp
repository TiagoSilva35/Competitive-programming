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

vector<string> can_be_formed_by_concatenation(const vector<string>& strings) {
    vector<string> results;
    unordered_set<string> string_set(strings.begin(), strings.end());

    for (const auto& str : strings) {
        bool found = false;
        for (size_t i = 1; i < str.length(); ++i) {
            string part1 = str.substr(0, i);
            string part2 = str.substr(i);

            if (string_set.find(part1) != string_set.end() && string_set.find(part2) != string_set.end()) {
                found = true;
                break;
            }
        }
        results.push_back(found ? "YES" : "NO");
    }
    return results;
}

void solve() {
    int n;
    cin >> n;
    vector<string> vs(n);
    forn(i,n){cin >> vs[i];}
    vector<string> ans = can_be_formed_by_concatenation(vs);
    for (auto i:ans){
        cout << i << endl;
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