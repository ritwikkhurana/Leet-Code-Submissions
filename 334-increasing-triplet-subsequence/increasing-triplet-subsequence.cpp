class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=INT_MAX,j=INT_MAX;
        for (int count = 0 ; count < nums.size() ; count++) {
            if (nums[count] < i) {
                i=nums[count];
            } else if (nums[count] > i && nums[count] < j) {
                j=nums[count];
            } else if (nums[count] > i && nums[count] > j) return true;
        }
        return false;
    }
};