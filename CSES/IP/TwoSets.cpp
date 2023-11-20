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
 
void solve(){
    ll n;
    cin >> n;
    vll v(n);
    ll sum = 0;
    vll firsthalf;
    vll secondhalf;
    forn(i, n) {v[i] = (i + 1);sum+=(i+1);}
    if ((sum & 1) ^ 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
        return;
    }
    ll target_sum = sum/2;
    
    firsthalf.push_back(n);target_sum-=n;
    for(int i = n-1; i > 0; i--){
        if (target_sum > 0){
            if (target_sum - i >= 0){
                firsthalf.push_back(i);
                target_sum -= i;
            }
            else{
                secondhalf.push_back(i);
                continue; 
            }
            
        }
        else{
            secondhalf.push_back(i);
        }
    }


    cout << sz(firsthalf) << endl;
    cout << firsthalf[0];
    for (ll i = 1; i < sz(firsthalf); i++)
    {
        cout << " " << firsthalf[i];
    }
    cout << endl;
    cout << sz(secondhalf) << endl;
    cout << secondhalf[0];
    for (ll i = 1; i < sz(secondhalf); i++)
    {
        cout << " " << secondhalf[i];
    }
    cout << endl;
    
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