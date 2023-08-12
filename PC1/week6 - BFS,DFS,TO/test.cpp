#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool bipartite(int start, int n);

vector<vector<bool>> MATRIX;
vector<int> colors;


int main(void) {
    int n, m;
    int a, b;
    bool flag;
    while(cin >> n >> m) {
        MATRIX.assign(310, (vector<bool>(310, false)));
        colors.assign(310, 0);
        for (int i=0; i<m-1; i++) {
            cin >> a >> b;
            MATRIX[a-1][b-1] = true;
            MATRIX[b-1][a-1] = true;
        }



        flag=true;
        for (int i=0; i<n && flag; i++) {
            if (colors[i]==0)
                flag = bipartite(i, n);
        }

        /*
        for (int i=0; i<n; i++)
            cout << colors[i] << " ";
        */

        if (!flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}



bool bipartite(int start, int n) {
    int t;
    queue<int> list;
    colors[start] = 1;
    list.push(start);
    while (!list.empty()) {
        t = list.front();
        list.pop();
        for (int i=0; i<n; i++) {
            if (MATRIX[t][i]   &&   colors[i]==0) {
                colors[i] = -colors[t];
                list.push(i);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int u=0; u<n; u++) {
            if (MATRIX[i][u]) {
                if (colors[i]+colors[u]!=0) {
                    return false;
                }
            }
        }
    }
    return true;
}

/*
8 5
1 2
2 3
4 5
6 7
7 8
*/


/*
8 5
1 2
2 3
4 5
6 7
7 8
5 7
2 4
1 4
1 3
3 5
1 2
2 5
1 5
*/
