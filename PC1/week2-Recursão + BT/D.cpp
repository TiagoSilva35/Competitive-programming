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

bool ANS = false;

void rec(int size,vi v,vector <bool> &used,int lado,int total,int idx){
    if (ANS)
        return;
    if (total == 0){
        ANS = true;
        return;
    }

    if(lado < 0)
        return;

    if (lado == 0){
        rec(size,v,used,size,total-size,idx);
    }

    for (int i = 0; i < (int)v.size(); i++)
    {
        if (!used[i]){
            used[i] = true;
            rec(size,v,used,lado-v[i],total,i);
            used[i] = false;
        }
    }
    return;
    
}

void solve(){
    int n,sum = 0;
    cin >> n;
    vi v(n);
    vector<bool>used(n,0);
    for (int i = 0; i < n; i++){cin >> v[i];sum+=v[i];};
    sort(all(v),greater<int>());
    if (sum % 4 != 0)cout << "no" << endl;
    else{
        int lado = sum/4;
        rec(lado,v,used,lado,sum,0);
        if (ANS)cout << "yes" << ln;
        else cout << "no" << ln;
    }
    ANS =  false;
    
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
        //cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}