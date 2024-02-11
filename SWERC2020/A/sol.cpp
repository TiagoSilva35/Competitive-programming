#include <bits/stdc++.h>
#include <cstdint>
#include <ios>
#include <limits>

using namespace std;

map<string, int> globl_mp;

bool compare(pair<string, int> a, pair<string, int> b){
	if (a.second == b.second ){
		return globl_mp[a.first] > globl_mp[b.first];
	}
	return a.second > b.second;
}

void solve(){
	int n, k;cin >> n >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	map<string, int> mp;
	int idx = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 3; ++j){	
			string a;
			getline(cin, a);
			mp[a]++;
			globl_mp[a] = idx;
			idx++;
		}
	}
	vector<pair<string, int>> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < min(k, (int)v.size()); i++){
		cout << v[i].first << endl;
	}
}

int main(){
	int t = 1;
	/* cin >> t; */
	for(int i = 0; i < t; i++){
		solve();
	}
}
