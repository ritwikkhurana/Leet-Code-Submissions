class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(3, {0,0}));
        vector<pair<int,int>> curr(3, {0,0});
        
        dp[n-1][1] = {0,prices[n-1]};
        dp[n-1][2] = {0,prices[n-1]};
        for (int i = n-2 ; i>= 0 ; i--) {
            for (int j = 0 ; j <= 2 ; j++) {
                if (j == 0) {
                    continue;
                }
                int buy = max(dp[i+1][j].first, -prices[i] + dp[i+1][j].second);
                int sell = max(dp[i+1][j].second, prices[i] + dp[i+1][j-1].first);
                dp[i][j] = {buy, sell};
            }
        }
        return dp[0][2].first;
    }
};