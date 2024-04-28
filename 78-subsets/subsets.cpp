class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        int n = nums.size();
        int subsets = 1 << n;
        for (int i = 0 ; i < subsets ; i++) {
            vector<int> subset;
            for (int j = 0 ; j < n ; j++) {
                if (i & (1 << j)) subset.push_back(nums[j]);
            }
            output.push_back(subset);
        }
        return output;
    }
};