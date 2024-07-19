class Solution {
public:
    int getMax(vector<int> &temp, int start, int end, vector<vector<int>> &dp) {
        int maxCoin = INT_MIN;
        if (start > end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        for (int i = start ; i <= end ; i++) {
            int cost = (temp[i] * temp[start-1] * temp[end+1]);
            int left = dp[start][i-1] != -1 ? dp[start][i-1] : getMax(temp, start,i-1,dp);
            int right = dp[i+1][end] != -1 ? dp[i+1][end] : getMax(temp, i+1, end,dp);
            cost += (left + right);
            maxCoin = max(maxCoin, cost);
        }
        return dp[start][end] = maxCoin;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(1);
        temp.insert(temp.end(), nums.begin(), nums.end());
        temp.push_back(1);
        int n = temp.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return getMax(temp, 1, temp.size()-2, dp);
    }
};