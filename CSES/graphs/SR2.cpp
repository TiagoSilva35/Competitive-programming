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
double eps = 1e-12;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void Floyd_Warshall(vector<vector<ll>>& matrix, ll numVertices) {
  for (int i = 0; i < numVertices; ++i){
    matrix[i][i] = 0;
  }
  for (ll k = 0; k < numVertices; k++) {
    for (ll i = 0; i < numVertices; i++) {
      for (ll j = 0; j < numVertices; j++) {
	if (matrix[i][k] != INT64_MAX && matrix[k][j] != INT64_MAX) {
	  matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	}
      }
    }
  }
}

void solve(){
  ll n, m, q; cin >> n >> m >> q;
  vector<vector<ll>> matrix(n + 1 ,vector<ll>(n + 1, INT64_MAX));
  for (int i = 0; i < m; ++i){
    ll a, b, c; cin >> a >> b >> c;a--;b--;
    matrix[a][b] = min(c, matrix[a][b]);
    matrix[b][a] = min(c, matrix[b][a]);
  }
  Floyd_Warshall(matrix, n);
  for (int i = 0; i < q; ++i){
    ll a, b; cin >> a >> b;a--;b--;
    cout << (matrix[a][b] >= INT64_MAX ? -1 : matrix[a][b]) << endl;
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
