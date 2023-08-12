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
    int n;
    cin >> n;
    vector<vector<bool>> matrix1(n+1, vector<bool>(n+1, false));
    int times;
    for (int i = 0; i < n; i++) {
        cin >> times;
        for (int j = 0; j < times; j++)
        {
            int dest;
            cin >> dest;
            matrix1[i][dest] = true;
        }
    }

    Floyd_Warshall(matrix1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && matrix1[i][j] == true)
            cout << i << endl;
        }
    }
    return 0;
}
