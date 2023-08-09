#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int times = 0; times < t; times++){
        string s, word;
        cin >> s >> word; 
        vector<char> l;
        vector<char> w;
        map<char, int> m;
        int i = 0, j = 0;

        transform(s.begin(), s.end(), s.begin(), ::tolower);
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        for (; i < (int)s.size(); i++){
            m[s[i]]++;
            if (i == (int)s.size() - 1 || s[i] != s[i + 1])
                l.push_back(s[i]);
        }

        for (; j < (int)word.size(); j++){
            if (j == (int)word.size() - 1 || word[j] != word[j + 1])
                w.push_back(word[j]);
        }

        bool flag = true;
        
        for (int i = 0; i < (int)word.size(); i++){
            if (m[word[i]] == 0){
                flag = false;
            }
            else{
                m[word[i]]--;
            }
        }

        if ((int)word.size() > (int)s.size() || m.find(word.back()) == m.end()){
            cout << "NO" << endl;
            flag = false;
        }
        else{
            for (auto key : m) {
                if (key.second < 0) {
                    flag = false;
                    break;
                }
            }

            for (int k = 0; k < (int)w.size(); k++){
                if (l[k] != w[k]){
                    flag = false;
                    break;
                }
            }

            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
