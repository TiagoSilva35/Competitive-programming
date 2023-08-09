#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int getMinOperations(int A, int B) {
    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({A, 0});
    visited.insert(A);

    while (!q.empty()) {
        int currA = q.front().first;
        int currOperations = q.front().second;
        q.pop();

        if (currA == B) {
            return currOperations;
        }

        for (int Ki = 1; Ki <= 10; Ki++) {
            int nextA_add = currA + Ki;
            int nextA_sub = currA - Ki;

            if (nextA_add <= B && visited.find(nextA_add) == visited.end()) {
                q.push({nextA_add, currOperations + 1});
                visited.insert(nextA_add);
            }

            if (nextA_sub >= 1 && visited.find(nextA_sub) == visited.end()) {
                q.push({nextA_sub, currOperations + 1});
                visited.insert(nextA_sub);
            }
        }
    }

    return -1;  // B is not reachable from A
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        int minOperations = getMinOperations(A, B);
        cout << minOperations << endl;
    }

    return 0;
}
