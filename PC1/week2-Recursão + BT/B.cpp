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

/*bool compare(vi a, vi b){
    if ((int)a.size() != (int)b.size())
        return (int)a.size() > (int)b.size();
    else{
        for (int i = 0; i < (int)a.size(); i++)
        {
            if(a[i] != b[i]){
                return a[i] < b[i];
            }
        }
    }
    return 0;
}*/
 
void print(vi comb){
    cout << comb[0];
    for (int i = 1; i < (int)comb.size(); i++)
    {
        cout << " " << comb[i];
    }
    cout << ln;
}

void rec(vi &v,vv &all_combs ,vi &comb,int target,int idx,int &counter){
    if (target == 0){
        vi temp;
        temp = comb; 
        all_combs.push_back(temp);
        temp.clear();
        counter++;
    }

    if (target < 0){
        return;
    }

    for (int i = idx; i < (int)v.size(); i++)
    {
        comb.push_back(v[i]);
        rec(v,all_combs,comb,target-v[i],i,counter);
        comb.pop_back();

    }
    return;
    
}

void solve(){
    int n,x;
    cin >> n >> x;
    vi v(n);
    vv all_combs;
    vi comb;
    int counter = 0;
    for(int i = 0; i < n; i++){cin>>v[i];};
    sort (all(v));
    rec(v,all_combs,comb,x,0,counter);
    //sort(all(all_combs),compare);
    cout << counter << ln;
    for (const auto &i:all_combs)
        print(i);

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