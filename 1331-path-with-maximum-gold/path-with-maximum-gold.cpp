class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis, int &maxPath, int n, int m) {
        vis[i][j] = 1;
        int left = (j > 0 && grid[i][j-1] != 0 && vis[i][j-1] != 1) ? dfs(grid, i, j-1, vis, maxPath,n,m) : 0;
        int right = (j < m-1 && grid[i][j+1] != 0 && vis[i][j+1] != 1) ? dfs(grid, i, j+1, vis, maxPath,n,m): 0;
        int up = (i > 0 && grid[i-1][j] != 0 && vis[i-1][j] != 1) ? dfs(grid, i-1, j, vis, maxPath,n,m): 0;
        int down = (i < n-1 && grid[i+1][j] != 0 && vis[i+1][j] != 1) ? dfs(grid, i+1, j, vis, maxPath,n,m): 0;
        int currMax = grid[i][j] + max(left, max(right, max(up,down)));
        maxPath = max(maxPath, currMax);
        vis[i][j] = 0;
        return currMax;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxPath = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] != 0) dfs(grid, i, j, vis, maxPath, n, m);
            }
        }
        return maxPath;
    }
};