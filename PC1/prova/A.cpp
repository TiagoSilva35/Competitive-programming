#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        count[num]++;
    }
    
    int minRemovals = 0;
    for (const auto& p : count)
    {
        int num = p.first;
        int freq = p.second;
        if (num > freq)
        {
            minRemovals += freq;
        }
        else if (num < freq)
        {
            minRemovals += freq - num;
        }
    }
    
    cout << minRemovals << endl;
    
    return 0;
}
