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

double ANS = numeric_limits<double>::infinity();

double d(int x1,int y1, int x2,int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

void min_dist(vpii&v,double cur,vector<bool>&check,vpii &temp,int idx){
    if (cur >= ANS){
        return;
    }

    if ((int)temp.size() == (int)v.size()){
        ANS = min(ANS,cur);
        return;
    }

    for (int i = 0; i < (int)v.size(); i++)
    {
        if(!check[i]){
            check[i] = true;
            temp.pb({v[i]});
            min_dist(v,cur+d(temp[idx].first,temp[idx].second,temp[i].first,temp[i].second),check,temp,i);
            check[i] = false;
            temp.pop_back();
        }
    }
    return;  
}

void solve(){
    int n;
    cin >> n;
    vpii v(n);
    for(int i = 0 ; i < n; i++){cin >> v[i].first >> v[i].second;}
    vector <bool> check(n);
    vpii temp;
    min_dist(v,0,check,temp,0);
    cout << ANS << ln;
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