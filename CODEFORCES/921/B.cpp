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

inline ll gcd (int a, int b){ 
  while(b){
    b = a % b;
    swap(a, b);
  }
  return a;
}

inline vi get_divisors(int n){
  vi divs;
  for (int i = 1; i < sqrt(n) + 1; ++i){
    if (n % i == 0){
      if (n/i == i)
	divs.push_back(i);
      else
	divs.push_back(i);
      divs.push_back(n/i);
    }
  }
  return divs;
}

void solve(){
  int x,n;cin >> x >> n;
  vi v = get_divisors(x);
  int ans = -1;
  for (auto d: v){
    if (x/d >= n){
      ans = max(ans, d);
    }
  }
  cout << ans << endl;
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
