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
 
 const ll di[] = {1, 0, -1, 0};
 const ll dj[] = {0, -1, 0, 1};

ll n, m, k;
ll ans = 0;
vector<vector<char>> grid;
vector<vector<bool>> visited;

bool valid(ll i, ll j){
    return i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == '.'; 
}

void dfs(ll i, ll j){
    visited[i][j] = true;
    forn(k,4){
        ll ni = i + di[k], nj = j + dj[k];
        if (valid(ni, nj) && !visited[ni][nj]){
            ans++;
            dfs(ni, nj);
        }
    }
}

void solve(){
    cin >> n >> m >> k;n+=2;m+=2;
    grid.resize(m, vector<char>(n, '.'));
    visited.resize(m, vector<bool>(n, false));
    forn (_, k){
        ll x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;x1++;x2++;y1++;y2++;
        for(ll i = x1; i <= x2; i++){
            for(ll j = y1; j <= y2; j++){
                grid[i][j] = '#';
            }
        }
        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    dfs(0, 0);
    cout << ans - (2 * n) - (2 * (m-2)) + 1 << endl;

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