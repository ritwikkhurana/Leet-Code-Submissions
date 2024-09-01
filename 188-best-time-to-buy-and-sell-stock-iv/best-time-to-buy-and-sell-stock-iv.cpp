class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2,0)));
        for (int i = n-1 ; i >=0 ; i--) {
            for (int j = 1 ; j <=k ; j++) {
                for (int k = 0 ; k < 2 ; k++) {
                    if (k==0) {
                        dp[i][j][0] = max(dp[i+1][j][0], -prices[i] + dp[i+1][j][1]);
                    } else {
                        dp[i][j][1] = max(dp[i+1][j][1], prices[i] + dp[i+1][j-1][0]);
                    }  
                }
            }
        }
        return dp[0][k][0];
    }
};