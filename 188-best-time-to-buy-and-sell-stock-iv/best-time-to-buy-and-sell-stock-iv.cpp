class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(k+1, {0,0}));
        for (int i = 1 ; i <= n; i++) {
            for (int j = 1 ; j <= k ; j++) {
                dp[i][j].first = max(dp[i-1][j].first, -prices[n-i] + dp[i-1][j].second);
                dp[i][j].second = max(dp[i-1][j].second, prices[n-i] + dp[i-1][j-1].first);
            }
        }
        return dp[n][k].first;
    }
};