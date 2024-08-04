class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalFlips = 0;
        for (int i = 0 ; i < n/2 ; i++) {
            for (int j = 0 ; j < m/2 ; j++) {
                int ones=0,zeros=0;
                grid[i][j] == 0 ? zeros++ : ones++;
                grid[i][m-j-1] == 0 ? zeros++ : ones++;
                grid[n-i-1][j] == 0 ? zeros++ : ones++;
                grid[n-i-1][m-j-1] == 0 ? zeros++ : ones++;
                totalFlips += (min(ones,zeros));
            }
        }
        int toFlip = 0;
        int palinOnes=0;
        if (n%2 == 1) {
            for (int i = 0 ; i < m/2 ; i++) {
                if (grid[n/2][i] != grid[n/2][m-i-1]) {toFlip++;}
                if (grid[n/2][i] == 1 && grid[n/2][m-i-1] == 1) palinOnes++;
            }
        }
        if (m%2 == 1) {
            for (int i = 0 ; i < n/2 ; i++) {
                if (grid[i][m/2] != grid[n-i-1][m/2]) {toFlip++;}
                if (grid[i][m/2] == 1 && grid[n-i-1][m/2] == 1) palinOnes++;
            }
        }
        if (n%2==1 && m%2==1 && grid[n/2][m/2] == 1) totalFlips++;
        totalFlips += toFlip;
        if (palinOnes % 2 == 1) {
            if (toFlip == 0) totalFlips += 2;
        }
        return totalFlips;
    }
};