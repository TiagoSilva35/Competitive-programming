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

void solve(){
    int n;
    cin >> n;
    vector<vector<char>> matriz(n, vector<char>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matriz[i][j];
        }
    }
    
    int counter = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //cout << matriz[i][j] << " " << matriz[n-1-j][i] << " " << abs(matriz[i][j] - matriz[n-1-j][i]) << " " << counter << endl;
            if (matriz[i][j] != matriz[n-1-j][i]){                
                int dist = max(max(matriz[i][j], matriz[n-1-j][i]), max(matriz[n-1-i][n-j-1],matriz[j][n-1-i]));
                counter += abs(dist - matriz[i][j]);
                matriz[i][j] = dist;

                counter += abs(dist - matriz[n-1-j][i]);
                matriz[n-1-j][i] = dist;

                counter += abs(dist - matriz[n-i-1][n-j-1]);
                matriz[n-1-i][n-1-j] = dist; 

                counter += abs(dist - matriz[j][n-i-1]);
                matriz[j][n-1-i] = dist;
            }
        }
    }
    cout << counter << endl;

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