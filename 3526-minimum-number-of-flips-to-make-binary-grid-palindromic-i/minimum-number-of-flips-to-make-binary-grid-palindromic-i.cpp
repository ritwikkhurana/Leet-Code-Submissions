class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int rowFlips = 0;
        for (int i = 0 ; i < n ; i++) {
            int start = 0, end=m-1;
            while (start < end) {
                if (grid[i][start] != grid[i][end]) rowFlips++;
                start++;
                end--;
            }
        }
        int colFlips = 0;
        for (int i = 0 ; i < m ; i++) {
            int start = 0, end=n-1;
            while (start < end) {
                if (grid[start][i] != grid[end][i]) colFlips++;
                start++;
                end--;
            }
        }
        return min(colFlips, rowFlips);
    }
};