class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = 0;
        for (int i: nums) {
            if (i == 1) totalOnes++;
        }
        int zeroCount = 0;
        vector<int> numsCopy(nums);
        numsCopy.insert(numsCopy.end(), nums.begin(), nums.end());
        int start = 0;
        int loop = 0;
        int minSwaps = INT_MAX;
        while (loop < numsCopy.size()) {
            if (numsCopy[loop] == 0) zeroCount++;
            int lenSub = loop-start+1;
            if (lenSub == totalOnes) {
                minSwaps = min(minSwaps, zeroCount);
            } else if (lenSub > totalOnes) {
                if (numsCopy[start] == 0) zeroCount--;
                start++;
                if (numsCopy[loop] == 0) zeroCount--;
                continue;
            }
            loop++;
        }
        return minSwaps;
    }
};