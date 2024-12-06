class Solution {
vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<int>> &vis, int ocean, int n, int m) {
        vis[r][c] = vis[r][c] == 0 ? ocean : (vis[r][c] == ocean ? vis[r][c] : 3);
        for (auto dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr >= 0 && nr < n && nc >=0 && nc < m) {
                if (heights[r][c] <= heights[nr][nc] && (vis[nr][nc] == 0 || (vis[nr][nc] != ocean && vis[nr][nc] != 3))) {
                    dfs(heights, nr, nc, vis, ocean, n, m);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> output;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n ; i++) {
            dfs(heights, i, 0, vis, 1, n, m);
            dfs(heights, i, m-1, vis, 2, n, m);
        }

        for (int i = 0; i < m ; i++) {
            dfs(heights, 0, i, vis, 1, n, m);
            dfs(heights, n-1, i, vis, 2, n, m);
        }

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (vis[i][j] == 3) output.push_back({i,j});
            }
        }
        return output;
    }
};