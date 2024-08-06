class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] == 1) continue;
            if (nums.size()-i < 3) return -1;
            nums[i+1] = nums[i+1] == 1 ? 0 : 1;
            nums[i+2] = nums[i+2] == 1 ? 0 : 1;
            op++;
        }
        return op;
    }
};