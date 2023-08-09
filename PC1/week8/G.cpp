#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Floyd_Warshall(vector<vector<bool>>& matrix) {
    int n = matrix.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
            }
        }
    }
}

bool areConnectionMatricesEqual(vector<vector<bool>>& matrix1, vector<vector<bool>>& matrix2) {
    int n = min((int)matrix1.size(),(int)matrix2.size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
            //cout << "1" << endl;
        }
    }
    return true;
}

int main() {
    int numTests;
    cin >> numTests;
    string line;
    getline(cin, line);
    for (int t = 0; t < numTests; t++) {
        int numEdges1, numEdges2;
        cin >> numEdges1;
        vector<vector<bool>> matrix1(26, vector<bool>(26, false));
        for (int i = 0; i < numEdges1; i++) {
            char src, dst;
            cin >> src >> dst;
            matrix1[src-'A'][dst-'A'] = true;
        }
        cin >> numEdges2;
        vector<vector<bool>> matrix2(26, vector<bool>(26, false));
        for (int i = 0; i < numEdges2; i++) {
            char src, dst;
            cin >> src >> dst;
            matrix2[src-'A'][dst-'A'] = true;
        }

        Floyd_Warshall(matrix1);
        /*for (int i = 0; i < numEdges1; i++)
        {
            for (int j = 0; j < numEdges1; j++)
            {
                cout << matrix1[i][j] << " ";
            }
            cout << endl;
        }*/
        
        Floyd_Warshall(matrix2);

        bool shouldRemove = areConnectionMatricesEqual(matrix1, matrix2);
        cout << (shouldRemove ? "YES" : "NO") << endl;

        if (t < numTests-1) {
            cout << endl;
            getline(cin, line);
        }
    }
    return 0;
}
