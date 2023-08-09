#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pwr(ll base, ll exponent, ll modulo) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulo;
        }
        base = (base * base) % modulo;
        exponent /= 2;
    }
    return result;
}

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
        num += i*(pwr(b,k-count,100000));
        count++;
    }
    if (num % 2 == 0)
        cout << "EVEN" << "\n";
    else
        cout << "ODD" << "\n";    
}
