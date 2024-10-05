class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &vis) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (auto dir: directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < n && newCol >=0 && newCol < m 
                && !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int numIslands = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(grid, i, j, vis);
                    numIslands++;
                }
            }
        }
        return numIslands;
    }
};