class Solution {
public:
    int sameParity(vector<int> &nums, int par) {
        int total = 0;
        for (int i: nums) {
            if (i%2 == par) total++;
        }
        return total;
    }
    int diffParity(vector<int> &nums, int par) {
        int total = 0;
        for (int i: nums) {
            if (i%2 == par) {
                total++;
                par = par == 1 ? 0 : 1; 
            }
        }
        return total;
    }  
    int maximumLength(vector<int>& nums) {
        return max(sameParity(nums, 0),max(sameParity(nums, 1), max(diffParity(nums, 0), diffParity(nums,1))));
    }
};