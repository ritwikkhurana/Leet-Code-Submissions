class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long finalScore = 0;
        int start = 0, index=-1;
        while (start < nums.size()) {
            if (start == nums.size()-1 || nums[start+1] >= nums[start]) {
                finalScore += nums[start];
                for (int i = start-2; i>=0 && i> index ; i=i-2) {
                    finalScore += nums[i];
                }
                index = start+1;
                start += 2;
            } else {
                start++;
            }
        }
        return finalScore;
    }
};