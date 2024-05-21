class Solution {
public:
    void help(vector<int>& nums, int l, vector<vector<int>> &output, vector<int> &temp, int n) {
        if (l >= n) {
            output.push_back(temp);
            return;
        }
        temp.push_back(nums[l]);
        help(nums, l+1, output, temp, n);
        temp.pop_back();
        help(nums, l+1, output, temp, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        vector<int> temp;
        help(nums, 0, output, temp, n);
        return output;
    }
};