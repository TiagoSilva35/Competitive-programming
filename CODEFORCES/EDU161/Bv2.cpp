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

const ll mxN = 3e5;
ll a[mxN] ,n;

void solve(){
  cin >> n;
  map<int, int> numOfLens;
  for (int i = 0; i < n; ++i)
    {
      int k; cin >> k;
      numOfLens[k]++;
    }
  ll res = 0;
  ll sum = 0;
  for (auto it: numOfLens){
    ll cnt = it.second;
    if (cnt >= 3){
      res += cnt * (cnt - 1) * (cnt - 2) / 6;
    }
    if (cnt >= 2){
      res += cnt * (cnt - 1)/2 * sum;
    }
    sum += cnt;
  }
  cout << res << "\n";
  
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
