class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxSum=0,currSum=0;
        unordered_set<int> count;
        int start=0,end=0;
        while (end < nums.size()) {
            currSum += nums[end];
            if (count.find(nums[end]) == count.end()) {
                maxSum = max(maxSum, currSum);
                count.insert(nums[end]);
            } else {
                while (nums[start] != nums[end]) {
                    count.erase(nums[start]);
                    currSum -= nums[start];
                    start++;
                }
                currSum -= nums[start];
                start++;
            }
            end++;
        }
        return maxSum;
    }
};