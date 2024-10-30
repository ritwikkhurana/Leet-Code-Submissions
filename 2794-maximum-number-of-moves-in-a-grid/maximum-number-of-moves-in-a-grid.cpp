class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxMoves = 0;
        for (int i = m-1 ; i>=0 ; i--) {
            for (int j = 0 ; j < n ; j++) {
                int right = (i < m-1 && grid[j][i+1] > grid[j][i]) ? 1+dp[j][i+1] : 0;
                int up = (i < m-1 && j > 0 && grid[j-1][i+1] > grid[j][i]) ? 1+dp[j-1][i+1] : 0;
                int down = (i < m-1 && j < n-1 && grid[j+1][i+1] > grid[j][i]) ? 1+dp[j+1][i+1] : 0;
                dp[j][i] = max(right,max(up,down));
            }
        }
        for (int i = 0 ; i < n ; i++) {
            maxMoves = max(maxMoves, dp[i][0]);
        }
        return maxMoves;
    }
};