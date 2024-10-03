class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int totalRem = 0;
        for (int i : nums) {
            totalRem = (totalRem + i)%p;
        }
        int rem = totalRem % p;
        if (rem == 0) return 0;
        unordered_map<int,int> ourmap;
        int currSum = 0;
        int ans = nums.size();
        ourmap[0] = -1;
        for (int i = 0 ; i < nums.size() ; i++) {
            currSum = (currSum+nums[i])%p;
            int needed = (currSum-rem+p)%p;
            if (ourmap.find(needed) != ourmap.end()) {
                ans = min(ans, i-ourmap[needed]);
            }
            ourmap[currSum] = i;
        }
        if (ans == nums.size()) return -1;
        return ans;
    }
};