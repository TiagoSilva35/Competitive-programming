#include <bits/stdc++.h>

using namespace std;

int main(){
    int b,k;
    cin >> b >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
    }
    int num = 0;
    int count = 1;
    for (auto i:v){
        num += i*(pow(b,k-count));
        count++;
    }
    if (num % 2 == 0)
        cout << "EVEN" << "\n";
    else
        cout << "ODD" << "\n";    
}