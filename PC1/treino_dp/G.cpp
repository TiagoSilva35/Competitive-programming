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
#define MAX 105

int memo[MAX][MAX];

int rec(int n1, int n2, vi &t1, vi &t2, int idx1, int idx2) {
    if (idx1 >= n1 || idx2 >= n2) return 0;
    if (memo[idx1][idx2] != -1) return memo[idx1][idx2];
    if (t1[idx1] == t2[idx2])memo[idx1][idx2] = 1 + rec(n1, n2, t1, t2, idx1 + 1, idx2 + 1);
    else memo[idx1][idx2] = max(rec(n1, n2, t1, t2, idx1 + 1, idx2), rec(n1, n2, t1, t2, idx1, idx2 + 1));
    return memo[idx1][idx2];
}
 

void solve(int n1,int n2){
    vi t1(n1);
    vi t2(n2);
    forn(i,n1){cin >> t1[i];}
    forn(i,n2){cin >> t2[i];}
    //forn(i,n1){forn(j,n2){cout << memo[i][j] << " ";}cout << endl;}
    cout << rec(n1,n2,t1,t2,0,0) << "\n\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n1,n2;
    int it = 0;
    while(cin >> n1 >> n2){
        if (n1 == 0 && n2 == 0)break;
        memset(memo,-1,sizeof(memo));
        cout << "Twin Towers #" << 1 + it << "\nNumber of Tiles : ";
        solve(n1,n2);
        it++;
    }
    return 0;
}