#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
    int t;
    cin >> t;
    while (t--) {
        lli n,sum=0;
        cin >> n;
        while(n>0){
            sum+=n;
            n/=2;
        }
    cout << sum << endl;
    }
    return 0;
}
