#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> v;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 998244353;
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
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void rec(int k ,int a,int b,int x, int y,int &count){
    if (k == 1)
        return;
    if (a > 2048 || b > 2048 || a < 0 || b < 0)
        return;

    if ((a-k/2 <= x && x <= a+k/2) && (b-k/2 <= y && y<= b+k/2)){
        //cout << "("<< a <<"," << b << ")" << "("<< x <<"," << y << ")" << ln;
        //cout << "Value of k: " << k << ln;
        count++;
    }
    //cout << "("<< a <<"," << b << ")" << "("<< x <<"," << y << ")" << ln;
    //cout << k << ln;
    rec(k/2,a+k/2,b-k/2,x,y,count);
    rec(k/2,a+k/2,b+k/2,x,y,count);
    rec(k/2,a-k/2,b-k/2,x,y,count);
    rec(k/2,a-k/2,b+k/2,x,y,count);
    return;



}

void solve(){
    int k,x,y;
    cin >> k >> x >> y;
    while(k != 0 || x != 0 || y != 0){
        int counter = 0;
        rec(2*k+1,1024,1024,x,y,counter);
        cout << right<< setw(3) << counter << ln;
        cin >> k >> x >> y;
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