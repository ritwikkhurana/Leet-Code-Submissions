class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int modulo = 1e9 + 7;
        vector<long long> subSum;
        for (int i = 0 ; i < n ; i++) {
            long long sum = 0;
            for (int j = i ; j < n ; j++) {
                sum += (long long)nums[j];
                subSum.push_back(sum);
            }
        }
        sort(subSum.begin(), subSum.end());
        int ans = 0;
        for (int i = left-1; i < right ; i++) {
            ans = (ans + (subSum[i])%modulo)%modulo;
        }
        return ans;
    }
};