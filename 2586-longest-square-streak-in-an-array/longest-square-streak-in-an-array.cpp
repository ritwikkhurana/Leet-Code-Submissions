class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        int maxSize = -1;
        sort(nums.begin(), nums.end());
        unordered_map<long,int> ourmap;
        for(int i = n-1 ; i>=0 ; i--) {
            int currCount = 1;
            if (ourmap.find((long)nums[i]*nums[i]) != ourmap.end()) {
                currCount = ourmap[nums[i]*nums[i]]+1;
            }
            ourmap[nums[i]] = currCount;
            maxSize = max(maxSize, currCount);
        }
        return maxSize == 1 ? -1 : maxSize;
    }
};