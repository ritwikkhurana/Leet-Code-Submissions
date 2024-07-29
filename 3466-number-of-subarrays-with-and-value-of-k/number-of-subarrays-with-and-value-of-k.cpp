class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int,int> prev;
        for (int i: nums) {
            unordered_map<int,int> curr;
            for (auto andVal: prev) {
                curr[andVal.first & i] += (andVal.second);
            }
            curr[i]++;
            for (auto loop: curr) {
                if (loop.first == k) ans += loop.second;
            }
            prev = curr;
        }
        return ans;
    }
};