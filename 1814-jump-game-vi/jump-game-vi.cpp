class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        deque<int> q;
        for (int i = n-1 ; i>=0; i--) {
            dp[i] += nums[i];
            while (!q.empty() && q.front() > i+k) q.pop_front();
            dp[i] += (q.empty() ? 0 : dp[q.front()]);
            while (!q.empty() && dp[i] >= dp[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return dp[0];
    }
};