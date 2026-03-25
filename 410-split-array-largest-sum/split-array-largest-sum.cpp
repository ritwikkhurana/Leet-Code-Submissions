class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
        dp[n-1][1] = nums[n-1];
        for (int i = 0 ; i < k ; i++) {
            dp[n][i] = 0;
        }
        for (int i = n-2 ; i>=0 ; i--) {
            for (int j = 1 ; j <= k ; j++) {
                int sum = 0;
                int minSum = INT_MAX;
                for (int ind = i ; ind < n ; ind++) {
                    sum += nums[ind];
                    if (dp[ind+1][j-1] != INT_MAX) minSum = min(minSum, max(sum, dp[ind+1][j-1]));
                }
                dp[i][j] = minSum;
            }
        }
        return dp[0][k];
    }
};