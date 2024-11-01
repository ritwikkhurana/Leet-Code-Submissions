class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = 1;
        for (int i = 1 ; i < n ; i++) {
            int maxCount = 0;
            for (int j = i-1 ; j >= 0 ; j--) {
                if (nums[j] < nums[i]) {
                    maxCount = max(maxCount, left[j]);
                }
            }
            left[i] = 1 + maxCount;
        }
        right[n-1] = 1;
        for (int i = n-2 ; i >= 0 ; i--) {
            int maxCount = 0;
            for (int j = i+1 ; j < n ; j++) {
                if (nums[j] < nums[i]) {
                    maxCount = max(maxCount, right[j]);
                }
            }
            right[i] = 1 + maxCount;
        }

        int minEle = INT_MAX;
        for (int i = 1 ; i < n-1 ; i++) {
            if (left[i] > 1 && right[i] > 1) {
                minEle = min(minEle, n-(left[i]+right[i]-1));
            }
        }
        return minEle;
    }
};