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

vi temp_comb;
vector<string> matrix;
int w,h;
const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};

bool valid(int i, int j){
    return (i >= 0 && j >= 0) && (i < (int)matrix.size() && j < (int)matrix.size()) && (matrix[i][j] == '.' || matrix[i][j] == 'X');
}

void ff(int i, int j, vector<vector<bool>> &visited){
    visited[i][j] = true;
    forn(k,4){
        int ni = i + di[k], nj = j + dj[k];
        if (valid(ni,nj) && !visited[ni][nj]){
            ff(ni, nj, visited);
        }
    }
}

void combs(vi &v, int idx, int n, vector<bool> visited, map<int,string> &m){
    if ((int)temp_comb.size() == n){
        vector<vector<bool>> visited1 (h, vector<bool>(w,false));
        for(int i = 1; i <= w; i++){
            matrix[i] = m[temp_comb[i-1]-1];
        }
        ff(0,0,visited1);
        if(visited1[h-1][w-1] == true){
            for(auto k:matrix){
                cout << k << endl;
            }
            exit(0);
        }
        return;
    }
    forn(i,n){
        if(!visited[i]){
            visited[i] = true;
            temp_comb.push_back(v[i]);
            combs(v,idx - 1, n, visited,m);
            temp_comb.pop_back();
        }
    }
}

void solve(){
    cin >> w >> h;
    vector<bool> visited(h-2, false);
    map<int,string> m;
    matrix.resize(h);
    int k = 0;
    forn(i,h){
        string temp;
        cin >> temp;
        if(find(all(matrix),'O') != matrix.end()){
            matrix[0] = temp;
        }
        else if(find(all(matrix),'X') != matrix.end()){
            matrix[h-1] = temp;
        }
        else{
            m[k++] = temp;
        }
    }
    vi v(h-2);
    forn(i,h-2){
        v[i] = i+1;
    }
    combs(v,0,h-2,visited,m);
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