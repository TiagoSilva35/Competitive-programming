#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

#include <iostream>
#include <unordered_set>
#include <vector>
#include <bitset>

using namespace std;

int minGroups(int n, vector<int>& numbers) {
    int groupCount = 0;
    vector<unordered_set<int>> groups;

    for (int num : numbers) {
        bool added = false;

        // Try to add the current number to an existing group
        for (int i = 0; i < groupCount; ++i) {
            bool validGroup = true;
            for (int j = 0; j < 31; ++j) {
                if ((groups[i].count(j) > 0) && ((num & (1 << j)) > 0)) {
                    validGroup = false;
                    break;
                }
            }

            if (validGroup) {
                groups[i].insert(num);
                added = true;
                break;
            }
        }

        // If the current number couldn't be added to any existing group, create a new group
        if (!added) {
            unordered_set<int> newGroup;
            newGroup.insert(num);
            groups.push_back(newGroup);
            groupCount++;
        }
    }

    return groupCount;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }

        int result = minGroups(n, numbers);
        cout << result << endl;
    }

    return 0;
}


