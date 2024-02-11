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
#define INF INT_MAX

void solve(){
  ll n; cin >> n;
  vector<ll> v(n);
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }
  ll ans = 0;
  sort(all(v));
  if (n == 1 || n == 2) {cout << v[0] << endl;return;}
  else if (n == 3) {cout << (v[0] + v[n-1]) - v[1] << endl;return;}
  else{
    ll i = 0, j = n-1;
    while (i < j){
      if (i + 1 != j - 1)
	ans = max(ans, abs((v[0] + v[n-1]) - (v[i] + v[j])));
      else{
	ans = max(ans, abs((v[0] + v[n-1]) - (v[i+1] + v[i] + v[j])));
      }
      i += 1; j -= 1;
    }
  }
  cout << ans << endl;
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
