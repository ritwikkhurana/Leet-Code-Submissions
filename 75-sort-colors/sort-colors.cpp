class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start=0,ind=0,end=n-1;
        while (ind <= end) {
            if (nums[ind] == 0) {
                swap(nums[start],nums[ind]);
                start++;
                ind++;
            } else if (nums[ind] == 2) {
                swap(nums[end], nums[ind]);
                end--;
            } else {
                ind++;
            }
        }
    }
};