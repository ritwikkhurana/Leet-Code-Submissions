class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start=0,end=n-1;
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] == target) return true;
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
                continue;
            }
            if (nums[start] < nums[end]) {
                if (target > nums[mid]) {
                    start = mid+1;
                } else {
                    end = mid-1;
                }
            } else {
                if (nums[mid] >= nums[start]) {
                    if (target < nums[mid] && target >= nums[start]) {
                        end = mid-1;
                    } else {
                        start = mid+1;
                    }
                } else {
                    if (target > nums[mid] && target <= nums[end]) {
                        start = mid+1;
                    } else {
                        end = mid-1;
                    }
                }
            }
        }
        return false;
    }
};