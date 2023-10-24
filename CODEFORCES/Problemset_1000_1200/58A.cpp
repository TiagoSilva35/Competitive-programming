#include <bits/stdc++.h>
#include <ostream>

using namespace std;

int main(){
	string s;
	cin >> s;
	string a;
	int i = 0;
	map<char,int> m;
	vector<bool> visited(4,false);
	while (i < (int)s.size()){
		if (s[i] == 'h'){
			visited[0] = true;
			if (m[s[i]] < 1)
				a += s[i]; 
			m[s[i]]++;
		}
		if (s[i] == 'e' && visited[0]){
			visited[1] = true;
			if (m[s[i]] < 1)
				a += s[i];
			m[s[i]]++;

		}
		if (s[i] == 'l' && visited[1]){
			m[s[i]] >= 1 ? visited[2] = true : visited[2] = false;
			if (m[s[i]] < 2)
				a += s[i];	
			m[s[i]]++;	 
		}
		if(s[i] == 'o' && visited[2]){
			visited[3] = true;
			if (m[s[i]] < 1){
				a += s[i];
			}
			m[s[i]]++;

		}
		i++;
	}
	size_t found = a.find("hello");
	//cout << a << endl;
	cout << (found == string::npos ? "NO" : "YES") << endl;
}