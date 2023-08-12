#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> homies, int M) {
    sort(homies.begin(), homies.end());
    int count = 1;
    int prevEnd = homies[0] + M;

    for (int i = 1; i < (int)homies.size(); i++) {
        if (homies[i] - M > prevEnd) {
            count++;
            prevEnd = homies[i] + M;
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int N, M;
        cin >> N >> M;
        vector<int> homies(N);

        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            homies[j] = temp; 
        }

        cout << partition(homies, M) << endl;
    }

    return 0;
}
