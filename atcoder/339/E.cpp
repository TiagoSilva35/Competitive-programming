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
ll t;
const ll mxN = 5e5 + 1;
ll arr[mxN];
int binarySearch(vector<int>& tails, int l, int r, int key) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (tails[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int lis3(ll a[], int n) {
        vector<int> tails(n, 0);
    int length = 1;  // length of LIS

    tails[0] = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < tails[0])
            tails[0] = a[i];
        else if (abs(a[i] - tails[length - 1]) <= t)
            tails[length++] = a[i];
        else {
            int pos = binarySearch(tails, -1, length - 1, a[i]);
            tails[pos] = a[i];
        }
    }

    return length;
}
ll lis(ll n){
  ll lis[n];
  lis[0] = 1;
  for (ll i = 1; i < n; i++) {
    lis[i] = 1;
    for (ll j = 0; j < i; j++)
      if (lis[i] < lis[j] + 1 && abs(arr[i] - arr[j]) <= t)
	lis[i] = lis[j] + 1;
  }
  // Return maximum value in lis[]
  return *max_element(lis, lis + n);
}

void solve(){
  ll n; cin >> n >> t;
  for (ll i = 0; i < n; ++i){
    cin >> arr[i];
  }
  cout << lis3(arr, n) << endl;
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
