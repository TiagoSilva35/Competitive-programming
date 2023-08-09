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
#define INF 2e16
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int n,tar,m=0,val;
vi peso(2001);
vi valor(2001);
vi ppp(201,0);
vv mat(2001,vi(5001,-1));

void bu(int u,int w){
    for (int i = 0; i <= w; ++i) {
        mat[0][i]=0;
    }
    int y=0;
    for (int i = 1; i <= u; ++i) {
        int lim=ppp[y];
        if (i==ppp[y+1]) y++;
        for (int j = 0; j <= w; ++j) {
            if (j-peso[i]<0) mat[i][j]=mat[i-1][j];
            else mat[i][j]=max(mat[i-1][j],mat[lim][j-peso[i]]+valor[i]);
        }
    }

}

int main() {

    cin>>n>>tar;
    ppp[0]=0;
    for (int i = 1; i <= n; ++i) {
        cin>>val;
        ppp[i]=ppp[i-1]+val;
        m+=val;
    }
    for (int i = 1; i <= m; ++i) {
        cin>>val;
        peso[i]=val;
        cin>>val;
        valor[i]=val;
    }
    bu(m,tar);

    cout<<mat[m][tar]<<endl;
    return 0;
}




