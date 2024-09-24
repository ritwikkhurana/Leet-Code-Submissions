class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        if (nums.size() == 1) return 1;
        int maxFreq = 1;
        int start=0,end=1;
        long long totalOp = 0;
        while (end < nums.size()) {
            totalOp += (nums[start]-nums[end]);
            while (totalOp > k && start < end) {
                totalOp -= (((long long)nums[start]-nums[start+1]) * (end-start));
                start++;
            } 
            maxFreq = max(maxFreq, end-start+1);
            end++;
        }
        return maxFreq;
    }
};