#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector<lli>DP(10001,-1);

int main(){
	int n;
	cin >> n;
	vector <int> nums(n);
	for(int i = 0; i < n ; i++){
		cin >> nums[i];
	}
	DP[0] = 1;
	for(int i = 1; i < n ; i++){
		DP[i] = 0;
		for(int j = 0; j<i ; j++){
			if(nums[j] < nums[i] && DP[i] < DP[j])
				DP[i] = DP[j];
		}
		DP[i] = DP[i] + 1;
	}
	cout << *max_element(DP.begin(),DP.end()) << endl;
}
