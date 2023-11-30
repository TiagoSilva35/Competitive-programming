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

vector<vector<vector<pair<string, int>>>> calcularPermutacoes(vector<pair<string, int>> equipe1, vector<pair<string,int>> equipe2) {
    vector<vector<pair<string,int>>> todasAsPessoas;
    todasAsPessoas.insert(todasAsPessoas.end(), equipe1.begin(), equipe1.end());
    todasAsPessoas.insert(todasAsPessoas.end(), equipe2.begin(), equipe2.end());

    vector<vector<vector<pair<string, int>>>> permutacoes;

    do {
        permutacoes.push_back(todasAsPessoas);
    } while (next_permutation(todasAsPessoas.begin(), todasAsPessoas.end()));

    return permutacoes;
}

void solve(){
    int D; cin >> D;
    int n;cin >> n;
    vector<pair<string, int>> SMI;
    forn(i, n){
        string a;cin >> a;int d; cin >> d;
        SMI[i] = make_pair(a, d);
    }
    int m;cin >> m;
    vector<pair<string, int>> CMP;
    forn(i, m){
        string a;cin >> a;int d; cin >> d;
        CMP[i] = make_pair(a, d);
    }
    vector<vector<vector<pair<string, int>>>> vvs = calcularPermutacoes(SMI, CMP);
    for (auto i: vvs){
        for(auto j:i){
            for (auto k:j){
                cout << k.first << " ";
            }
        }
        cout << endl;
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