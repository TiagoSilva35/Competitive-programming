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

void solve(){
  int h, w, n; cin >> h >> w >> n;
  vector<vector<char>> v(h, vector<char>(w, '.'));
  pair<int,int> cur = {0,0};
  char dir = 'u';
  for (int i = 0; i < n; ++ i){
        if (v[cur.first][cur.second] == '.'){
      v[cur.first][cur.second] = '#';
      if (dir == 'u'){
	dir = 'r';
       	cur = {cur.first, (cur.second + 1) % w};
      }
      else if (dir == 'r'){
	dir = 'd';
	cur = {(cur.first + 1) % h, cur.second};
      }
      else if (dir == 'd'){
	dir = 'l';
	cur = {cur.first, (cur.second - 1 + w)% w};
      }
      else if (dir == 'l'){
	dir = 'u';
	cur = {(cur.first - 1 + h )% h, cur.second};
      }
      continue;
    }
     if (v[cur.first][cur.second] == '#'){
      v[cur.first][cur.second] = '.';
      if (dir == 'u'){
	dir = 'l';
	cur = {cur.first, (cur.second - 1 + w) % w};
      }
      else if (dir == 'r'){
	dir = 'u';
	cur = {(cur.first - 1 + h) % h, cur.second};
      }
      else if (dir == 'd'){
	dir = 'r';
	cur = {cur.first, (cur.second + 1) % w};
      }
      else if (dir == 'l'){
	dir = 'd';
	cur = {(cur.first + 1) % h, cur.second};
      }
    }
  }
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      cout << v[i][j];
    }
    cout << endl;
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
