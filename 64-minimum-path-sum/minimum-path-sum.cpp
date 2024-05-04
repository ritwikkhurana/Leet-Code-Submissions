class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for (int i = n-1 ; i>=0 ; i--) {
            for (int j = m-1 ; j>=0 ; j--) {
                int sum = grid[i][j];
                int right = INT_MAX,down=INT_MAX;
                if (i < n-1) down = dp[i+1][j];
                if (j < m-1) right = dp[i][j+1];
                if (down == INT_MAX && right == INT_MAX) {
                    dp[i][j] = sum;
                } else {
                    dp[i][j] = sum + min(down,right);
                }
            }
        }
        return dp[0][0];
    }
};