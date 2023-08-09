#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    vector <int> buyers(N);
    vector <int> houses(M);
    for (int i = 0; i < N; i++)
    {
        cin >> buyers[i];
    }
    for (int j = 0; j < M; j++)
    {
        cin >> houses[j];
    }
    sort(buyers.begin(),buyers.end());
    sort(houses.begin(),houses.end());

    int ANS = 0;
    int buyers_index = 0;
    for (int i = 0; i < (int)houses.size(); i++){
        while (buyers_index < N && houses[i] >= buyers[buyers_index]-K){
            if (houses[i] <= buyers[buyers_index]+K){
                ANS++;
                buyers_index++;
                break;
            }
            buyers_index++;
        }
    }
    cout << ANS << endl;
    
    
}