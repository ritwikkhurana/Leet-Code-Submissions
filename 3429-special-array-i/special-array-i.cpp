class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;
        int flag = nums[0]%2==0 ? 1 : 0;
        for (int i = 1 ; i < n ; i++) {
            if (flag == 0) {
                if (nums[i]%2==0) {
                    flag = 1;
                } else {
                    return false;
                }
            } else {
                if (nums[i]%2!=0) {
                    flag = 0;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};