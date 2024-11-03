class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        int lowBound=INT_MAX,upperBound=-1;
        vector<int> output;
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) lowBound = min(lowBound, mid);
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        if (lowBound == INT_MAX) return {-1,-1};
        output.push_back(lowBound);
        start=0,end=nums.size()-1;
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) upperBound = max(upperBound, mid);
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        output.push_back(upperBound);
        return output;
    }
};