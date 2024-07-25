class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        unordered_map<int,int> ourmap;
        int n = nums.size();
        int start=0,end=n-1;
        while (start < end) {
            int diff = abs(nums[end]-nums[start]);
            ourmap[diff]++;
            start++;
            end--;
        }
        vector<int> allDiffs(k+1, 0);
        start=0,end=n-1;
        while (start < end) {
            int maxEle = max(nums[start],nums[end]);
            int minEle = min(nums[start],nums[end]);
            int maxDiff = max(k-minEle, maxEle-0);
            allDiffs[maxDiff]++;
            start++;
            end--;
        }
        for (int i = k-1 ; i >= 0 ; i--) {
            allDiffs[i] += allDiffs[i+1];
        }

        int minOp = INT_MAX;
        for (auto i: ourmap) {
            int oneOp = allDiffs[i.first]-i.second;
            int totalOp = oneOp + 2*(n/2-oneOp-i.second);
            minOp = min(minOp, totalOp);
        }
        return minOp;
    }
};