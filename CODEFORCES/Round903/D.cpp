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
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    vector <ll> primos;
    int size = 2;
    primos.pb(1);
    primos.pb(2);
    for (int i = 3; i <= 100000; i++){
        bool flag = true;
        for (int j = 1; j < size; j++){
            if (i%primos[j] == 0){
                flag = false;
                break;
            }
        }
        if (flag){
            primos.pb(i);
            size++;
        }
    }
    cin >> t;
    
    for(int it=1;it<=t;it++) {
        vector <ll> nprimos(size, 0);
        ll n, val;
        vector <ll> array;
        cin>>n;
        forn(i, n){
            cin>>val;
            array.pb(val);
        }
        forn (i, n){
            val = array[i];
            if (val == 1) nprimos[0]++;
            for (ll j = 1; j < size; j++){
                if (val == 1) break;
                if (val%primos[j] == 0){
                    nprimos[j]++;
                    val /= primos[j];
                    j--;
                }
            }
        }
        bool flag = true;
        if (nprimos[0] != n){
            for (ll i = 1; i < size; i++){
                if (nprimos[i]%n != 0){
                    flag = false;
                    break;
                }
            }
        }
        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}