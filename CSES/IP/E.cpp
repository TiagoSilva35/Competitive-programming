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
 //1 2 3 4
 // 4 2 3 1 
 // 1 2 3 4 5 
 // 5 3 1 4 2 
//1 2 3 4 5 6 7 8
//8 6 4 2 7 5 3 1
//1 2 3 4 5 6
// 6 4 2 5 3 1
// 
void solve(){
    ll n;
    cin >> n;
    if (n == 1)cout << 1 << endl;
    if (n < 4 && n != 1){cout << "NO SOLUTION\n";}
    else if (n == 4)cout << 2 << " " << 4 << " " << 1 << " " << 3 << "\n";
    else{
        for(int i = n; i > 0 ; i-=2){
            cout << i << " ";
        }
        for(int i = n-1; i > 0 ; i-=2){
            cout << i << " ";
        }
        cout << "\n";
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