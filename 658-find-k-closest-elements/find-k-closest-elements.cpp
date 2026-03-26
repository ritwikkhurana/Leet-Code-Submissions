class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int target) {
    int left = 0;
    int right = nums.size() - k;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target - nums[mid] > nums[mid + k] - target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return vector<int>(nums.begin() + left, nums.begin() + left + k);
    }
};