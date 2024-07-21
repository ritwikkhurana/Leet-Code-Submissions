class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> count_x(m, 0);
        vector<int> count_y(m, 0);
        int total = 0;
        for (int i = 0 ; i < n ; i++) {
            int curx=0;
            int cury=0;
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == 'X') count_x[j]++;
                if (grid[i][j] == 'Y') count_y[j]++;
                curx += count_x[j];
                cury += count_y[j];
                if (curx == cury && curx > 0) total++;
            }
        }
        return total;
    }
};