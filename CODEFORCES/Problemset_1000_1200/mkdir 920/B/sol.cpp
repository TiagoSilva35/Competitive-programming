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
  int n; cin >> n;
  string s, f; cin >> s >> f;
  int i = 0;
  ll ansA = 0, ansB = 0, changes = 0;
  while (i < n){
    if (f[i] == '1' && s[i] == '0')
 	ansB++;
    else if (f[i] == '0' && s[i] == '1')
      ansA++;
   ++i;
  }
  cout << max(ansA, ansB) << endl;
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
