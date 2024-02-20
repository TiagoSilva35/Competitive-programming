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
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
const int mxN = 2e5;
int sumOfDigitsFrom1ToNUtil(int n, int a[]) 
{ 
    if (n < 10) 
        return (n * (n + 1) / 2); 
     
    int d = (int)(log10(n)); 
    int p = (int)(ceil(pow(10, d))); 
    int msd = n / p; 
     
    return (msd * a[d] + (msd * (msd - 1) / 2) * p + 
            msd * (1 + n % p) + 
            sumOfDigitsFrom1ToNUtil(n % p, a)); 
} 
int sumOfDigitsFrom1ToN(int n) 
{ 
    int d = (int)(log10(n)); 
    int a[d + 1]; 
    a[0] = 0; a[1] = 45;
     
    for(int i = 2; i <= d; i++) 
        a[i] = a[i - 1] * 10 + 45 * 
               (int)(ceil(pow(10, i - 1))); 
    return sumOfDigitsFrom1ToNUtil(n, a);
} 

void solve(){
    int n; cin >> n;
    cout << sumOfDigitsFrom1ToN(n) << endl;
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