#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        int diff = std::abs(a - b);
        int count = diff / 10;
        int remainder = diff % 10;

        if (remainder > 0) {
            count++;
        }

        cout << count << std::endl;
    }

    return 0;
}
