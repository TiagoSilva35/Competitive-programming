#include <bits/stdc++.h>

using namespace std;

bool canWIN(char matrix[3][3],char c){
    for (int i = 0; i < 3; i++)
    {
        if(matrix[i][0] == c && matrix[i][1] == c && matrix[i][2] == '-'){
            return true;
        }
        if(matrix[i][0] == c && matrix[i][1] == '-' && matrix[i][2] == c){
            return true;
        }
        if(matrix[i][0] == '-' && matrix[i][1] == c && matrix[i][2] == c){
            return true;
        }  
    }
    for (int i = 0; i < 3; i++)
    {
        if(matrix[0][i] == c && matrix[1][i] == c && matrix[2][i] == '-'){
            return true;
        }
        if(matrix[0][i] == c && matrix[1][i] == '-' && matrix[2][i] == c){
            return true;
        }
        if(matrix[0][i] == '-' && matrix[1][i] == c && matrix[2][i] == c){
            return true;
        }  
    }
    if(matrix[0][0] == c && matrix[1][1] == c && matrix[2][2] == '-'){
        return true;
    }
    if(matrix[0][0] == c && matrix[1][1] == '-' && matrix[2][2] == c){
        return true;
    }
    if(matrix[0][0] == '-' && matrix[1][1] == c && matrix[2][2] == c){
        return true;
    }
    if(matrix[0][2] == c && matrix[1][1] == c && matrix[2][0] == '-'){
        return true;
    }
    if(matrix[0][2] == c && matrix[1][1] == '-' && matrix[2][0] == c){
        return true;
    }
    if(matrix[0][2] == '-' && matrix[1][1] == c && matrix[2][0] == c){
        return true;
    }
    return false;

    
}

int main(){
    char matrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char temp;
            cin >> temp;
            if (temp == '|') {
                j--;
            } else {
                matrix[i][j] = temp;
            }
        }
    }
    bool xCanWin = canWIN(matrix, 'X');
    bool oCanWin = canWIN(matrix, 'O');

    if (xCanWin && oCanWin) {
        cout << "BOTH CAN WIN" << endl;
    } else if (xCanWin) {
        cout << "ONLY X CAN WIN" << endl;
    } else if (oCanWin) {
        cout << "ONLY O CAN WIN" << endl;
    } else {
        cout << "NO ONE CAN WIN" << endl;
    }

}