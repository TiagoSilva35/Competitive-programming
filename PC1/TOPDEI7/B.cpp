#include <bits/stdc++.h>

using namespace std;

#define lli long long int

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        lli N;
        cin >> N;
        if(N%4 == 0)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    
    }
    
}