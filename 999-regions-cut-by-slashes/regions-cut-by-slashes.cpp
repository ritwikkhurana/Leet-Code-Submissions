class Solution {
public:
    void dfs(vector<vector<int>> &dp, vector<vector<int>> &vis, int i, int j, int m) {
        vis[i][j] = 1;
        if (i > 0 && !vis[i-1][j] && !dp[i-1][j]) dfs(dp, vis, i-1, j, m);
        if (i < m-1 && !vis[i+1][j] && !dp[i+1][j]) dfs(dp, vis, i+1, j, m);
        if (j > 0 && !vis[i][j-1] && !dp[i][j-1]) dfs(dp, vis, i, j-1, m);
        if (j < m-1 && !vis[i][j+1] && !dp[i][j+1]) dfs(dp, vis, i, j+1, m);
        if (i > 0 && j > 0 && !vis[i-1][j-1] && !dp[i-1][j-1] && (dp[i-1][j] != 1 || dp[i][j-1] != 1)) dfs(dp, vis, i-1, j-1, m);
        if (i > 0 && j < m-1 && !vis[i-1][j+1] && !dp[i-1][j+1] && (dp[i-1][j] != -1 || dp[i][j+1] != -1)) dfs(dp, vis, i-1, j+1, m);
        if (i < m-1 && j > 0 && !vis[i+1][j-1] && !dp[i+1][j-1] && (dp[i+1][j] != -1 || dp[i][j-1] != -1)) dfs(dp, vis, i+1, j-1, m);
        if (i < m-1 && j < m-1 && !vis[i+1][j+1] && !dp[i+1][j+1] && (dp[i+1][j] != 1 || dp[i][j+1] != 1)) dfs(dp, vis, i+1, j+1, m);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(2*n, vector<int>(2*n, 0));
        for (int i = 0 ; i < 2*n ; i=i+2) {
            for (int j = 0 ; j < 2*n ; j=j+2) {
                int x = i/2;
                int y = j/2;
                if (grid[x][y] == '\\') {
                    dp[i][j] = -1;
                    dp[i+1][j+1] = -1;
                } else if (grid[x][y] == '/') {
                    dp[i][j+1] = 1;
                    dp[i+1][j] = 1;
                }
            }
        }
        int regions = 0;
        vector<vector<int>> vis(2*n, vector<int>(2*n, 0));
        for (int i = 0 ; i < 2*n ; i++) {
            for (int j = 0 ; j < 2*n ; j++) {
                if (!dp[i][j] && !vis[i][j]) {
                    dfs(dp, vis, i, j, 2*n);
                    regions++;
                }
            }
        }
        return regions;
    }
};