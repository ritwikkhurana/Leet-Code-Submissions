class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start=0,end=n-1;
        int ele = INT_MAX;
        while (start <= end) {
            int mid = start + (end-start)/2;
            ele = min(ele, nums[mid]);
            if (nums[start] <= nums[mid]) {
                if (nums[start] < nums[end]) {
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            } else {
                end = mid-1;
            }
        }
        return ele;
    }
};