class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, false));
        dp[0][0] = true;
        for (int i = 1 ; i <= m ; i++) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-2];
            } else {
                dp[0][i] = false;
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    bool ans1 = dp[i][j-2];
                    bool ans2;
                    char prev = p[j-2];
                    if (prev == '.' || s[i-1] == p[j-2]) {
                        ans2 = dp[i-1][j-2] || dp[i-1][j];
                    } else {
                        ans2 = dp[i][j-2];
                    }
                    dp[i][j] = ans1 || ans2;
                }
            }
        }
        return dp[n][m];
    }
};