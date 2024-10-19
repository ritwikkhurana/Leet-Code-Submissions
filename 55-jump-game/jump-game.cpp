class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        int currReach = 0;
        if (n == 1) return true;
        for (int i = 0 ; i < n ; i++) {
            maxReach = max(maxReach, i+nums[i]);
            if (currReach == i) {
                currReach = maxReach;
            }
            if (currReach >= n-1) break;
        }
        return currReach < n-1 ? false : true;
    }
};