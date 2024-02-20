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
#define ar array
void solve(){
  vector<ar<int, 2>> p;
  for (int i = 0; i < 4; ++i){
    int a, b; cin >> a >> b;
    p.push_back({a, b});
  }
  int minx = 1001, maxx =-1001, miny = 1001, maxy =-1001;
  for (auto i : p){
    minx = min(minx, i[0]);
    maxx = max(maxx, i[0]);
    miny = min(miny, i[1]);
    maxy = max(maxy, i[1]);
  }
  cout << (maxx - minx) * (maxy - miny) << endl;  
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
