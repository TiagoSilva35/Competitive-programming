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

vi parent(10001);

void makeSet(int v) {
    parent[v] = v;
}
int findSet(int v) {
    if (v != parent[v])
        parent[v] = findSet(parent[v]);
    return parent[v];
}
void unionSets(int u, int v) {
    int root1 = findSet(u);
    int root2 = findSet(v);
    parent[root2] = root1;
}
bool check(int u, int v) {
    return findSet(u) == findSet(v);
}

void solve(){
    int n,m;
    cin >> n >> m;
    forsn(i,1,n+1){makeSet(i);}
    for(int i = 0; i < m ; i++){
        int u,v;
        cin >> u >> v;
        unionSets(u,v);
    }
    map<int,int> ANS;
    int final_ans = 0;
    forsn(i,1,n+1){ANS[findSet(i)]++;}
    for(auto & i:ANS){
        if (i.second != 0){
            final_ans++;
        }
    }
    cout << final_ans << endl;

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