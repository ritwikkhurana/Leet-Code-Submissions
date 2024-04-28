class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> freq(m,vector<int>(10,0));
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                freq[j][grid[i][j]]++;
            }
        }
        vector<vector<int>> dp(m,vector<int>(10,INT_MAX));
        for (int i = 0 ; i <= 9 ; i++) {
            dp[m-1][i] = n - freq[m-1][i];
        }

        for (int i = m-2 ; i>=0 ; i--) {
            for (int k = 0 ; k <= 9 ; k++) {
                int minop = INT_MAX;
                for (int j = 0 ; j <= 9 ; j++) {
                    if (k==j) continue;
                    minop = min(minop, dp[i+1][j]);
                }
                dp[i][k] = minop + (n-freq[i][k]);
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};