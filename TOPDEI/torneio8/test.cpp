#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Função para calcular as probabilidades
void calculateProbabilities(int D, vector<pair<string, int>> &SMI, vector<pair<string, int>> &CMP) {
    int smiWins = 0, cmpWins = 0, totalScenarios = 0;

    // Gerar todas as sequências possíveis
    for (auto &smiMiner : SMI) {
        for (auto &cmpMiner : CMP) {
            int depth = 0;
            bool smiTurn = true;

            while (depth < D) {
                depth += smiTurn ? smiMiner.second : cmpMiner.second;
                if (depth >= D) {
                    if (smiTurn) smiWins++;
                    else cmpWins++;
                    break;
                }
                smiTurn = !smiTurn;
            }

            totalScenarios++;
        }
    }

    // Calcular as probabilidades
    cout << (smiWins * 100 / totalScenarios) << "% " << (cmpWins * 100 / totalScenarios) << "%" << endl;
}

int main() {
    int D, I, P;
    cin >> D;
    cin >> I;
    vector<pair<string, int>> SMI(I);
    for (int i = 0; i < I; i++) {
        cin >> SMI[i].first >> SMI[i].second;
    }
    cin >> P;
    vector<pair<string, int>> CMP(P);
    for (int i = 0; i < P; i++) {
        cin >> CMP[i].first >> CMP[i].second;
    }

    calculateProbabilities(D, SMI, CMP);
    return 0;
}
