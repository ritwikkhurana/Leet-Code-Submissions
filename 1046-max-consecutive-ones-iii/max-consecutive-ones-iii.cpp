class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0,start=0,end=0,zeroCount=0;
        while (end < nums.size()) {
            if (nums[end] == 0) zeroCount++;
            while (zeroCount > k) {
                if (nums[start] == 0) zeroCount--;
                start++;
            }
            maxLen = max(maxLen, end-start+1);
            end++;
        }
        return maxLen;
    }
};