#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareStrings(const string& s1, const string& s2) {
    return (s1 + s2) < (s2 + s1);
}

string lexicoConcatenation(const vector<string>& strings) {
    vector<string> sortedStrings(strings);
    sort(sortedStrings.begin(), sortedStrings.end(), compareStrings);

    string result;
    for (const string& s : sortedStrings) {
        result += s;
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<string> strings(N);
    for (int i = 0; i < N; i++) {
        cin >> strings[i];
    }

    string concatenatedString = lexicoConcatenation(strings);
    cout << concatenatedString << endl;

    return 0;
}
