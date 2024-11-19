class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ourmap;
        long long maxSum = 0;
        long long currSum = 0;
        int start=0,end=0;
        while (end < nums.size()) {
            int currSize = end-start+1;
            currSum += nums[end];
            ourmap[nums[end]]++;
            if (currSize > k) {
                ourmap[nums[start]]--;
                if (ourmap[nums[start]] == 0) ourmap.erase(nums[start]);
                currSum -= nums[start];
                start++;
                currSize--;
            }
            if (currSize == k && ourmap.size() == k) {
                maxSum = max(maxSum, currSum);
            }
            end++;
        }
        return maxSum;
    }
};