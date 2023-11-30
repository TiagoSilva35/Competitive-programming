#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int manuelWins = 0, joaoWins = 0;

    for (int i = 0; i < N; ++i) {
        char manuelChoice, joaoChoice;
        std::cin >> manuelChoice >> joaoChoice;

        if (manuelChoice == joaoChoice) continue;

        if ((manuelChoice == 'P' && joaoChoice == 'R') ||
            (manuelChoice == 'R' && joaoChoice == 'T') ||
            (manuelChoice == 'T' && joaoChoice == 'P')) {
            manuelWins++;
        } else {
            joaoWins++;
        }
    }

    std::cout << manuelWins << " " << joaoWins << std::endl;

    return 0;
}
