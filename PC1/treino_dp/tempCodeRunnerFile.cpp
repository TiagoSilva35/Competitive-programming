long long max_val(int idx, vector<int>& values, vector<int>& weights, int W, int n, vector<vector<long long>>& memo) {
   if (idx == n || W == 0) {
       return 0;
   }
   if (memo[idx][W] != -1) {
       return memo[idx][W];
   }
   if (weights[idx] > W) {
       memo[idx][W] = max_val(idx + 1, values, weights, W, n, memo);
   }
   else {
       memo[idx][W] = max(max_val(idx + 1, values, weights, W, n, memo),
                          max_val(idx + 1, values, weights, W - weights[idx], n, memo) + values[idx]);
   }
   return memo[idx][W];
}