#include <bits/stdc++.h>

using namespace std;

int c = 0;
int endTime = 0;

struct Movie {
    int startTime;
    int endTime;
};

bool sortByEndTime(const Movie& a, const Movie& b) {
    return a.endTime < b.endTime;
}

int maximumMovies(vector<Movie>& movies) {
    sort(movies.begin(), movies.end(), sortByEndTime);
    for (const Movie& movie : movies) {
        if (movie.startTime >= endTime) {
            c++;
            endTime = movie.endTime;
        }
    }

    return c;
}

int main() {
    int N;
    cin >> N;

    vector<Movie> movies(N);
    for (int i = 0; i < N; i++) {
        cin >> movies[i].startTime >> movies[i].endTime;
    }

    int maxMovies = maximumMovies(movies);
    cout << maxMovies << endl;

    return 0;
}
