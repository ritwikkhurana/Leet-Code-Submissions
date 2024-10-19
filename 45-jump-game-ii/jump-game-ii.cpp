class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        int currReach = 0;
        int jumps = 0;
        if (n == 1) return 0;
        for (int i = 0 ; i < n ; i++) {
            maxReach = max(maxReach, i+nums[i]);
            if (currReach == i) {
                jumps++;
                currReach = maxReach;
            }
            if (currReach >= n-1) break;
        }
        return currReach < n-1 ? -1 : jumps;
    }
};