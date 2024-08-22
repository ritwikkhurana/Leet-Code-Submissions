class Solution {
public:
    int help(string &s, int start, int end, vector<vector<int>> &dp) {
        if (start > end) return 0;
        if (start == end) return 1;
        if (dp[start][end] != -1) return dp[start][end];
        int minOp = INT_MAX;
        for (int i = start+1 ; i <= end ; i++) {
            int left = help(s, start, i-1,dp);
            int right = help(s, i, end,dp);
            if (s[start] == s[i]) {
                minOp = min(minOp, left+right-1);
            } else {
                minOp = min(minOp, left+right);
            }
        }
        return dp[start][end] = minOp;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return help(s, 0, n-1, dp);
    }
};