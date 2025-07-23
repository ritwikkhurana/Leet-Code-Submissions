class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while (i > 0) {
            if (nums[i-1] < nums[i]) break;
            i--;
        }
        if (i == 0) {
            sort(nums.begin(), nums.end());
        } else {
            int j = n-1;
            while (j >= i) {
                if (nums[j] > nums[i-1]) break;
                j--;
            }
            swap(nums[i-1], nums[j]);
            sort(nums.begin() + i, nums.end());
        }


    }
};