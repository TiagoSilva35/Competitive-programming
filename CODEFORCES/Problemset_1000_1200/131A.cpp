#include <bits/stdc++.h>
#include <cctype>
#include <iterator>

using namespace std;

int main(){
	string s;
	cin >> s;	
	if (s[0] >= 'A' && s[0] <= 'Z'){
		for (int i = 1; i < (int)s.size(); ++i)
		{
			if (s[i] >= 'a' && s[i] <= 'z'){
				cout << s << endl;
				return 0;
			}
		}
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << s << endl;
		return 0;
	}
	else{
		for (int i = 1; i < (int)s.size(); ++i){
			if (s[i] >= 'a' && s[i] <= 'z'){
				cout << s << endl;
				return 0;
			}
		}
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		s[0] = toupper(s[0]);
		cout << s << endl;
		return 0;
	}
}