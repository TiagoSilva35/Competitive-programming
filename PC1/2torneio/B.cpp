#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findMaxGcdInRange(int A, int B, int L, int H) {
    int gcdAB = gcd(A, B);
    if (gcdAB >= L && gcdAB <= H)
        return gcdAB;
    for (int i = H; i >= L; i--) {
        if (A % i == 0 && B % i == 0)
            return i;
    }

    return -1;
}

int main() {
    int A, B;
    cin >> A >> B;

    int T;
    cin >> T;

    while (T--) {
        int L, H;
        cin >> L >> H;

        int maxGcd = findMaxGcdInRange(A, B, L, H);
        cout << maxGcd << endl;
    }

    return 0;
}
