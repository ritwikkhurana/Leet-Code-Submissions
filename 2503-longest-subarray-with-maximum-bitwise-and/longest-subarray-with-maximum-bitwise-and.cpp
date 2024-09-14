class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen=1,currLen=1,maxNum=nums[0],prev=0;
        for (int i = 1 ; i < nums.size() ; i++) {
            if (nums[i] > maxNum) {
                maxLen = 1;
                currLen = 1;
                maxNum = nums[i];
            } else if (nums[i] == maxNum) {
                if (nums[i] == nums[prev]) {
                    currLen++;
                    maxLen = max(maxLen, currLen);
                } else {
                    currLen = 1;
                }
            }
            prev = i;
        }
        return maxLen;
    }
};