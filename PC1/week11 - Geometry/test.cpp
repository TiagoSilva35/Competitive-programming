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

bool compare (pii a, pii b){
    if (a.second != b.second){
        return a.second > b.second;
    }
    else{
        return a.first < b.first;
    }
}

void solve(){
    int M,N,K;
    cin >> N >> M >> K;
    vpii v(M);
    forn(i,N){
        string s;
        cin >> s;
        for (int j = 0 ; j < M ; j ++){
            if (s[j] == '1'){
                v[j].second++;
            }
            v[j].first = j;
        }
    }
    sort(all(v),compare);
    cout << v[0].first + 1; 
    for(int i = 1; i < K ; i++)cout << " " << v[i].first + 1;
    cout << ln;

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