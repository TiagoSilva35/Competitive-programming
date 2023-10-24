#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
const int MAX_COST = 10000;

struct Card {
    string name;
    int cost;
    int attack;
    int defense;
};
int S, C, N;
int dp[MAX_N][MAX_COST];
vector<Card> cards;

pair<int, vector<Card>> maximizePower(int idx, int cost) {
    if (idx < 0 || cost <= 0) {
        return {0, {}};
    }

    if (dp[idx][cost] != -1) {
        return {dp[idx][cost], {}};
    }

    pair<int, vector<Card>> notSelected = maximizePower(idx - 1, cost);

    if (cards[idx].cost <= cost) {
        pair<int, vector<Card>> selected = maximizePower(idx - 1, cost - cards[idx].cost);
        selected.first += cards[idx].attack + cards[idx].defense;
        selected.second.push_back(cards[idx]);

        if (selected.first > notSelected.first) {
            dp[idx][cost] = selected.first;
            return selected;
        }
    }

    dp[idx][cost] = notSelected.first;
    return notSelected;
}

int main() {
    int S, C, N;
    cin >> S >> C >> N;

    cards.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i].name >> cards[i].cost >> cards[i].attack >> cards[i].defense;
    }

    memset(dp, -1, sizeof(dp));

    pair<int, vector<Card>> result = maximizePower(N - 1, C);

    int totalCost = 0;
    for (const Card& card : result.second) {
        totalCost += card.cost;
    }
    if (!totalCost){
        cout << "No solution" << endl;
        return 0;
    }
    cout << (int)result.second.size() << " " << result.first << " " << totalCost << endl;

    for (const Card& card : result.second) {
        cout << card.name << endl;
    }

    return 0;
}
