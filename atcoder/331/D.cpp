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

const int mxN = 1e9;
int n,n1,m1,n2,m2;
vector<vector<int>>visited(1001, vector<int>(1001,0));
vector<vector<char>>grid(1001,vector<char>(1001,'a'));

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};

bool valid(int i, int j){
    return i >= n1 && j >= n2 && i <= m1 && j <= m2;
}
int ans = 0;
void dfs(int i, int j){
    visited[i][j] = 1;
    for(int k = 0; k < 4; ++k){
        int ni = i + di[k], nj = j + dj[k];
        if (valid(ni, nj) && !visited[ni][nj]){
            ans = grid[ni][nj] == 'B' ? ans : ans + 1;  
            dfs(ni,nj);  
        }
    }
}

void solve(){
    cin >> n;
    int q;
    cin >> q;
    forn(i,n){
        forn(j,n){
            char a;cin >> a;
            grid[i][j] = a;
        }
    }
    for (int i = 0; i < q; ++i){
        ans = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        n1 = x1, n2 = y1, m1 = x2, m2 = y2;
        dfs(x1,y1);
        cout << ans << endl; 
    }
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