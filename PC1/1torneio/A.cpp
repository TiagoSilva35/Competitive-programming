#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int times = 0; times < t; times++)
    {
        string s;
        cin >> s;
        bool flag = 0;
        for (int i = 0; i < (int)s.size()/2; i++)
        {
            if (s[i] != s[s.size()-i-1]){
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if (!flag){
            cout << "YES" << endl;
        }
        
    }
    
}