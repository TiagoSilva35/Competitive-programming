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

vv memo(51,vi(5001,-1));

int rec(string &key,string &txt,int idxKey,int idxTxt){
    if (idxKey == (int)key.size()){
        return 1; 
    }
    if (idxTxt == (int)txt.size()){
        return 0;
    }
    if(memo[idxKey][idxTxt] != -1){
        return memo[idxKey][idxTxt];
    }
    int ans = 0;
    if (key[idxKey] == txt[idxTxt]){
        ans += rec(key,txt,idxKey+1,idxTxt+1);
        ans %= MOD;
        memo[idxKey][idxTxt] = ans;
    }
    
    ans += rec(key,txt,idxKey,idxTxt+1);
    ans %= MOD;
    memo[idxKey][idxTxt] = ans;
    return ans;
}


void solve(){
    memo.assign(51,vi(5001,-1));
    string keyword, text;
    cin >> keyword;
    cin.ignore(); 
    getline(cin, text);
    cout << rec(keyword,text,0,0) << endl;

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