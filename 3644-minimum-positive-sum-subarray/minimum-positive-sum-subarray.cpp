class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;
        for (int i = l ; i <= r ; i++) {
            int start=0,end=0;
            int currSum = 0;
            while (end < n) {
                currSum += nums[end];
                int currSize = end-start+1;
                while (currSize > i) {
                    currSum -= nums[start];
                    start++;
                    currSize = end-start+1;
                }
                if (currSize == i && currSum > 0) minSum = min(minSum, currSum);
                end++;
            }
        }
        return minSum == INT_MAX ? -1 : minSum;
    }
};