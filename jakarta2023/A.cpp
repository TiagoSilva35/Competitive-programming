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
 
int di[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dj[] = {0, 0, -1, 1, -1, 1, -1, 1};

pii a = {0,0};

bool valid(int i,int j,vector<vector<bool>> visited){
    if (i < 3  && j < 3 && !visited[i][j]){
        return true;
    }
    return false;
}

void solve(){
    int n = 3;
    vector<string> vs(n);
    int mx = INF;
    forn(i,n){
        string a;
        cin >> a;
        vs[i] = a;
    }
    vector<vector<bool>> visited(3, vector<bool> (3, false));
    forn(i,3){
        forn(j,3){
            if ((int)vs[i][j] < mx){
                a = {i, j};
                mx = (int)vs[i][j];
            }
        }
    }
    visited[a.first][a.second] = true;
    int tmp = 1;
    string ans = "";
    ans += char(mx);
    pii mtp = {0,0};
    vpii mtps;
    mtps.push_back(mtp);
    int min_temp = INF;
    for (int i = 0; i < 8; ++i){
        if (valid(a.first + di[i], a.second + dj[i], visited)){
            if (min_temp >= (int)vs[a.first + di[i]][a.second + dj[i]]){
                mtp.first = a.first + di[i];
                mtp.second = a.second + dj[i];
                mtps.push_back(mtp);
            }
        }
    }
    map<pii,int> mp;
    for (auto kappa: mtps){
        int min_temp = INF;
        for (int i = 0; i < 8; ++i){
            if (valid(a.first + di[i], a.second + dj[i], visited)){
                if (min_temp >= (int)vs[a.first + di[i]][a.second + dj[i]]){
                    mtp.first = a.first + di[i];
                    mtp.second = a.second + dj[i];
                }
            }
        }
        mp[kappa] = vs[mtp.first][mtp.second];
    }
    tmp++;
    int gh = INF;
    pii o = {0,0};
    for (auto i:mp){
        if ((int)vs[i.first.first][i.first.second] < ans){
            ans = vs[i.first.first][i.first.second];
            //o = {i.first,i.second};
        }
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