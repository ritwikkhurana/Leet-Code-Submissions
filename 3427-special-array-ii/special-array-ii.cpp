class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 1 ; i < n ; i++) {
            if ((nums[i]&1) ^ (nums[i-1]&1) == 0) {
                prefix[i] = prefix[i-1] + 1;
            } else {
                prefix[i] = prefix[i-1];
            }
        }
        vector<bool> output;
        for (auto i: queries) {
            if (prefix[i[0]] == prefix[i[1]]) {
                output.push_back(true);
            } else {
                output.push_back(false);
            }
        }
        return output;
    }
};