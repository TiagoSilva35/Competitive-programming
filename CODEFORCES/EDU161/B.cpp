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

const int mxN = 3e5;
int a[mxN + 1], n;
vi comb;

int rec (int idx){
  int counter = 0;
  if (comb.size() == 3){
    //cout << comb[0] << " " << comb[1] << " " << comb[2] << endl;
    if (comb[0] < comb[1] + comb[2] && comb[1] < comb[0] + comb[2] && comb[2] < comb[1] + comb[0]){
      return 1;
    }
    return 0;
  }
  for (int i = idx; i < n; ++i){
    comb.push_back(a[i]);
    counter += rec(i + 1);
    comb.pop_back();
  }
  return counter;
}

void solve(){
  cin >> n;
    for (int i = 0; i < n; ++i){
    int k; cin >> k;
    a[i] = pow(2, k);
  }
  cout << rec(0) << endl;
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
