class Solution {
public:
    int ceil2(int x) {
        if (x%2 == 0) return x/2;
        return (x/2)+1;
    }
    int minArraySum(vector<int>& nums, int l, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(op1+1, vector<int>(op2+1, INT_MAX)));
        for (int i = 0 ; i <= op1 ; i++) {
            for (int j = 0 ; j <= op2 ; j++) {
                dp[0][i][j] = 0;
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 0 ; j <= op1 ; j++) {
                for (int k = 0 ; k <= op2 ; k++) {
                    if (j == 0 && k == 0) {
                        dp[i][j][k] = nums[i-1] + dp[i-1][0][0];
                    } else if (k == 0) {
                        dp[i][j][k] = min(nums[i-1] + dp[i-1][j][0], ceil2(nums[i-1]) + dp[i-1][j-1][0]);
                    } else if (j == 0) {
                        dp[i][j][k] = nums[i-1] + dp[i-1][0][k];
                        if (nums[i-1] >= l) {
                            dp[i][j][k] = min(dp[i][j][k], nums[i-1]-l + dp[i-1][0][k-1]);
                        }
                    } else {
                        dp[i][j][k] = min(nums[i-1] + dp[i-1][j][k], ceil2(nums[i-1]) + dp[i-1][j-1][k]);
                        if (nums[i-1] >= l) {
                            dp[i][j][k] = min(dp[i][j][k], min(nums[i-1]-l + dp[i-1][j][k-1], ceil2(nums[i-1]-l) + dp[i-1][j-1][k-1]));
                        }
                        if (ceil2(nums[i-1]) >= l) {
                            dp[i][j][k] = min(dp[i][j][k], ceil2(nums[i-1])-l + dp[i-1][j-1][k-1]);
                        }
                    }
                }
            }
        }
        return dp[n][op1][op2];
    }
};