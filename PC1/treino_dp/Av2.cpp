#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Function to count the occurrences of the keyword as a subsequence in the text
int countSubsequences(string& keyword, string& text, int i, int j, vector<vector<int>>& memo) {
    if (j == keyword.length()) {
        return 1;
    }

    if (i == text.length()) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int ans = 0;

    if (text[i] == keyword[j]) {
        ans += countSubsequences(keyword, text, i + 1, j + 1, memo);
        ans %= MOD;
    }

    ans += countSubsequences(keyword, text, i + 1, j, memo);
    ans %= MOD;

    return memo[i][j] = ans;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        string keyword, text;
        cin >> keyword;
        cin.ignore(); 
        getline(cin, text);

        int keywordLen = keyword.length();
        int textLen = text.length();
        vector<vector<int>> memo(textLen, vector<int>(keywordLen, -1));

        int ans = countSubsequences(keyword, text, 0, 0, memo);
        cout << ans << endl;
    }

    return 0;
}
