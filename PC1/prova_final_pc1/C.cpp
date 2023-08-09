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
 

double feliz_max = 0;
vector<vector<int>> matrix(1001, vector<int>(1001));
vector<vector<int>>memo(10001,vector<int>(1001,-1));
vector<int> best_comb;

void rec(int idx, vector<int>& combination, int n, int m, vector<int>& dishes) {
    int total = 0;
    for(auto dish : combination){
        for(int i = 0; i < n; i++){
            total += matrix[i][dish-1];
        }
    }
    if (memo[idx][total] != -1)return;

    if (!combination.empty()){
        double feliz = total * total / (double) combination.size();
        if (feliz > feliz_max){
            feliz_max = feliz;
            best_comb = combination;
            memo[idx][total] = feliz_max;
        }
    }
    for (int i = idx ; i < m ; i++){
        combination.push_back(dishes[i]);
        rec(i+1, combination, n, m, dishes);
        combination.pop_back();
    }
}
//i3wm
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++){
            cin >> matrix[i][j];
        }
    }
    vector<int> dishes(m);
    iota(dishes.begin(), dishes.end(), 1);
    vector<int> combination;
    feliz_max = 0;
    best_comb.clear(); 

    rec(0, combination, n, m, dishes);
    
    for (int dish : best_comb)
        cout << dish << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    cin >> t;
    for(int it = 1; it <= t; it++) {
        solve();
    }
    return 0;
}
