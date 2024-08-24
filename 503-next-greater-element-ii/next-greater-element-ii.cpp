class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> circ(nums);
        circ.insert(circ.end(), nums.begin(), nums.end()-1);
        vector<int> output;
        for (int i = 0 ; i < n ; i++) {
            int ele = nums[i];
            int j;
            for (j = i+1 ; j < circ.size() ; j++) {
                if (circ[j] > nums[i]) {
                    output.push_back(circ[j]);
                    break;
                }
            }
            if (j >= circ.size()) output.push_back(-1);
        }
        return output;
    }
};