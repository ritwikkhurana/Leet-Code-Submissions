class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, int n, int m) {
        vis[i][j] = 1;
        if (i > 0 && grid[i-1][j] && !vis[i-1][j]) dfs(grid, vis, i-1, j,n,m);
        if (j > 0 && grid[i][j-1] && !vis[i][j-1]) dfs(grid, vis, i, j-1,n,m);
        if (i < n-1 && grid[i+1][j] && !vis[i+1][j]) dfs(grid, vis, i+1, j,n,m);
        if (j < m-1 && grid[i][j+1] && !vis[i][j+1]) dfs(grid, vis, i, j+1,n,m);
    }
    int countIslands(vector<vector<int>>& grid, int n, int m) {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int components = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] && !vis[i][j]) {
                    dfs(grid, vis, i, j, n, m);
                    components++;
                }
            }
        }
        return components;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = countIslands(grid, n, m);
        if (islands != 1) return 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    int islands = countIslands(grid, n, m);
                    if (islands != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};