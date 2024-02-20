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
  int n, ini, cpu, cto; cin >> n >> ini >> cpu >> cto;
  vi times(n);
  for (int i = 0; i < n; ++i){
    cin >> times[i];
  }
  ll cur_time = 0;
  for (auto time: times){
    ll dif = time - cur_time;
    ini = dif * cpu < cto ? ini - dif * cpu : ini - cto;
    cur_time += dif;
    if (ini <= 0){
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
