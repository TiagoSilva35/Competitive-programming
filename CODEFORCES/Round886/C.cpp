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
    vector<string> matrix(8);
    forn(i,8){
        string a;
        cin >> a;
        matrix[i] = a;
    }
    bool flag = false;
    vector<char>ANS;
    forn(i,8){
        forn(j,8){
            char nbr = matrix[i][j];
            if (nbr != '.'){
                while(nbr != '.'){
                    ANS.push_back(nbr);        
                    if (i == 7){
                        flag = true;
                        break;
                    }
                    nbr = matrix[i+1][j];
                    i++;
                }
                break;
            }
            if (flag)break;
        }
        if (flag)break;
    }
    for(auto i:ANS){
        cout << i;
    }
    cout << "\n";
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