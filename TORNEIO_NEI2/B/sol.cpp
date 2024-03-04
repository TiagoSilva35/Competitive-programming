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
   int N, S; 
   cin >> N >> S;
    vector<int> A(N+2);
    A[0] = 1001; A[N] = 1001;

    for (int i = 1; i < N; i++) {
        cin >> A[i];
    }   
    map<int, int> valley;
    map<int, int> peak;
    for(int i = 2; i < N-2; i++) {
        if(A[i] > A[i-1] && A[i] > A[i+1]) {
            peak[i] = 1;
        }
        if(A[i] < A[i-1] && A[i] < A[i+1]) {
            valley[i] = 1;
        }
    }

    if(peak[S] == 1 || valley[S] == 1) {
        cout << 0 << endl;
        return;
    }

    bool right = false;
    if(A[S] < A[S-1] || S == 1) {
        right = true;
    }

    if(right) {
        for(int i = S; i < N-1; i++) {
            if(valley[i] == 1) {
                cout << abs(i-S) << endl;
                return;
            }
        }
    } 
    else {
        for(int i = S; i > 1; i--) {
            if(valley[i] == 1) {
                cout << abs(i-S) << endl;
                return;
            }
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