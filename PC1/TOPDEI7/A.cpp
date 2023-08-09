#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    double value = 0.00;
    for (int i = 0; i < t; i++)
    {
        double D,V;
        cin >> D >> V;
        value += (V*(D/3600.0));
    }
    cout << fixed << setprecision(2) << value << endl;
    
}