#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void Floyd_Warshall(vector<vector<int>>& matrix) {
    int numVertices = (int)matrix.size();
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
}

int main() {
    int numVertices, numEdges, source, target;
    cin >> numVertices >> numEdges;

    vector<vector<int>> matrix(numVertices, vector<int>(numVertices, INT_MAX));

    for (int i = 0; i < numVertices; i++) {
        matrix[i][i] = 0;
    }

    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u - 1][v - 1] = w;
    }

    Floyd_Warshall(matrix);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> source >> target;
        if (matrix[source - 1][target - 1] == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << matrix[source - 1][target - 1] << endl;
        }
    }

    return 0;
}
