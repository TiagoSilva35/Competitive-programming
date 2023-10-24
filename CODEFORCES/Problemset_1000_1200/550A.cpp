#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

//ABA
bool checkIfvalid(unordered_map<string,int> &m, vector<bool> visited, string s){
	m["AB"] = 0;
	m["BA"] = 0;
	for (int i = 0; i < (int)s.size() - 1; ++i){
		if (s[i] == 'A' && !visited[0]){
			if (s[i+1] == 'B'){
				visited[0] = true;
				i++;
				m["AB"]++;
			}
			continue;
		}
		if (s[i] == 'B'){
			if (s[i+1] == 'A' && !visited[1]){
				visited[1] = true;
				i++;
				m["BA"]++;
			}
			continue;
		}
	}
	return ((m["AB"] > 0 && m["BA"] > 0) ? true : false);
}

int main(){
	string s;
	cin >> s;
	unordered_map<string,int> m;
	m["AB"] = 0;
	m["BA"] = 0;
	vector<bool> visited(2, false); 
	bool valid1 = checkIfvalid(m, visited, s);
	reverse(s.begin(),s.end());
	bool valid2 = checkIfvalid(m, visited, s);
	cout << (valid1 || valid2 ? "YES" : "NO") << endl; 
}