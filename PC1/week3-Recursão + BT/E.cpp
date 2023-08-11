#include <bits/stdc++.h>

using namespace std;

int ANS = 0;

bool ss(vector<int>v,int n,int cur_sum,int target,int idx);

int main(void){
    int n,x;
    cin >> n >> x;
    vector<int>vals(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];
        s+= vals[i];
    }
    sort(vals.begin(),vals.end(),greater<int>());

    if (s < x)
        cout << "NO" << endl;

    else if (s == x)
        cout << "YES" << endl;

    else{
        if(ss(vals,n,0,x,0))
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }
    
}

bool ss(vector<int>v,int n,int cur_sum,int target,int idx){
    if(cur_sum > target)
        return false;

    if (cur_sum == target)
        return true;

    if (idx == n)
        return false;

    return ss(v,n,cur_sum+v[idx],target,idx+1) || ss(v,n,cur_sum,target,idx+1);
    
}
