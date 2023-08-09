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
#define MAX_N 100

int n, m, visited[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];
 
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
 
bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == 'A';
}

void bfs_ff(int start_i, int start_j) {
    stack<pair<int, int>> st;
    st.push({start_i, start_j});
    visited[start_i][start_j] = 1;

    while (!st.empty()) {
        int i = st.top().first;
        int j = st.top().second;
        st.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (valid(ni, nj) && !visited[ni][nj]) {
                visited[ni][nj] = 1;
                st.push({ni, nj});
            }
        }
    }
}

int countLakes() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (valid(i, j) && !visited[i][j]) {
                bfs_ff(i, j);
                ans++;
            }
        }
    }
    return ans;
}

void solve() {
	memset(visited,0,sizeof(visited));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int lakes = countLakes();
    cout << lakes << "\n";
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