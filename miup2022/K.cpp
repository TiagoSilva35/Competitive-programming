
#include <bits/stdc++.h> 
#include <cstdio>
#include <locale>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve(){
	int num_with_contract, total_flights;
	cin >> num_with_contract;
	vector<string> airlines;
	forn(i, num_with_contract){
		string a;
		cin >> a;
		airlines.push_back(a);
	}
	cin >> total_flights;
	map <int, int> mp;
	vector<string>cts = {"Lisbon", "Porto", "Faro", "Funchal", "Beja"};
	forn(i, total_flights){
		string company, city1, time1, city2, time2;
		int day1, day2;
		cin >> company >> city1 >> day1 >> time1 >> city2 >> day2 >> time2;
		bool found = false;
		if (find(all(airlines), company) != airlines.end()){
			if (find(all(cts),city1) != cts.end()){
				mp[day1]++;
				found = true;
			}
			if (find(all(cts), city2) != cts.end() && (!found || day1 != day2)){
				mp[day2]++;
			}
		}
	} 
	pii temp_mx = {1,0};
	for (auto i: mp){
		if (i.second > temp_mx.second){
			temp_mx = i;
		}
	}
    cout << temp_mx.first << endl << temp_mx.second << endl;
	

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