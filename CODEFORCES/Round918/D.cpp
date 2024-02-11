#include <bits/stdc++.h>

using namespace std;

void solve(){
    string ans = "";
    int n;string s;cin >> n >> s;
    vector<char> vowels = {'a', 'e'};
    vector<char> consonants = {'b', 'c', 'd'};
    if (n == 3 || n == 2){cout << s << endl;return;}

    for (int i = 2; i < n; ++i){
        if ((find(consonants.begin(), consonants.end(), s[i]) != consonants.end() && find(consonants.begin(), consonants.end(), s[i + 1]) != consonants.end())){
            ans += s[i-2];
            ans += s[i-1];
            ans += s[i];
            ans += '.';
            i += 2;
        }
        if (find(consonants.begin(), consonants.end(), s[i]) != consonants.end() && find(vowels.begin(), vowels.end(), s[i + 1]) != vowels.end()){
            ans += s[i-2];
            ans += s[i-1];
            ans += '.';i++;
        }
        if ((n - i > 0 && n - i <= 2) ||(n - i > 0 && n - i <= 1)){
            ans += s.substr(i-1, n);
            break;
        }
    }
    cout << ans << endl;

}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        solve();
    }
}
