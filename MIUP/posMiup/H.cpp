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

vector<string> temp;
vector<string> ans;
int total_cost = 0;
int mx = 0;
vector<int>precalc;

void create_deck(vector<pair<string,vi>> &v, int S, int C, int N, int temp_mx,vector<bool> &visited, int idx){
    if ((int)temp.size() + N - idx - 1 < S) return;
    if (C < 0) return;
    int remaining_power = 0;
    for (int i = idx; i < N; i++) {
        remaining_power += v[i].second[1] + v[i].second[2];
    }

    int upper_bound = temp_mx + remaining_power;
    if (upper_bound <= mx) return;
    if ((int)temp.size() > S) return;
    if ((int)temp.size() == S  && C >= 0 && temp_mx > mx){
        ans = temp;
        mx = temp_mx;
        total_cost = C;
        return;
    }
    forn(i,N){
        if (!visited[i]){
            visited[i] = true;
            temp.push_back(v[i].first);
            create_deck(v, S, C - v[i].second[0], N, temp_mx + v[i].second[1] + v[i].second[2], visited, i);
            visited[i] = false;
            temp.pop_back();
        } 
    }
}

//S -> number of cards to be selected, C -> max allowed deck cost, N -> total cards
//name of the card, cost of the card, attack val, defense val
void solve(){
    ll S, C, N;
    cin >> S >> C >> N;
    vector<pair<string,vi>> v(N);
    forn(i,N){
        string s;
        ll cost, at, def;
        cin >> s >> cost >> at >> def;
        v[i].first = s;
        v[i].second.push_back(cost);
        v[i].second.push_back(at);
        v[i].second.push_back(def);
    }

    vector<bool>visited(N,false);
    create_deck(v, S, C, N, 0, visited,0);    
    if ((int)ans.size() == 0){
        cout << "No Solution" << endl;
        return;
    }
    cout << S << " " << mx << " " << C - total_cost << endl;
    for(auto i: ans){
        cout << i << endl;
    }
    //choose S cards. maximize power. cant go above the cost
    //power is the sum of attack and defense
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