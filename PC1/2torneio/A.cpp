#include <bits/stdc++.h>

using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>>matrix(m+10,vector<int>(n+10,0));
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {

            char c;
            cin >> c;
            if(c == '*')
                matrix[i][j] = -1;
        }  
    }
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (matrix[i][j] == -1)
                cout << "*";
            else{
                int aux = 0;
                if (matrix[i+1][j] == -1)aux++;
                if (matrix[i][j+1] == -1)aux++;
                if (matrix[i+1][j+1] == -1)aux++;
                if (matrix[i-1][j] == -1)aux++;
                if (matrix[i][j-1] == -1)aux++;
                if (matrix[i-1][j-1] == -1)aux++;
                if (matrix[i+1][j-1] == -1)aux++;
                if (matrix[i-1][j+1] == -1)aux++;
                cout << matrix[i][j] + aux;

            }
        }
        cout << endl;
        
    }
    
}