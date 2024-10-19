class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        priority_queue<pair<int,int>> pq;
        for (int i = n-1 ; i>=0; i--) {
            dp[i] += nums[i];
            while (!pq.empty() && pq.top().second > (i+k)) pq.pop();
            if (!pq.empty()) {
                dp[i] += dp[pq.top().second];
            }
            pq.push({dp[i], i});
        }
        return dp[0];
    }
};