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

bool rec(vi &v,int sumA ,int target,vector<bool>&visited,vv &memo){
    if (sumA == target/2){
        return true;
    }
    if (sumA >= target){
        return false;
    }
    if(memo[sumA][target])
        return memo[sumA][target];

    forn(i,(int)v.size()){
        if(!visited[i]){
            visited[i] = true;
            memo[sumA][target] = rec(v,sumA + v[i],target,visited,memo);
            if (memo[sumA][target]){
                return true;
            }
            visited[i] = false;
        }
    }
    return false;
    
}

void solve(){
    int n;
    cin >> n;
    vv memo(n,vector<int>(n,-1));
    vector<int>v(n);
    vector<bool>visited(n,false);
    int target = 0;
    forn(i,n){cin >> v[i];target+=v[i];}
    if (target % 2 != 0)
        cout << "NO" << ln;
    else if ((find(v.begin(),v.end(),1) == v.end() || find(v.begin(),v.end(),2) == v.end()) && (n % 2 != 0)){
        cout << "NO" << ln;
    }
    else{
        if(rec(v,0,target,visited,memo))
            cout << "YES" << ln;
        else
            cout << "NO" << ln;
    }
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