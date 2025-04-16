class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n, pivot);
        int s=0,e=n-1;
        for (int i = 0 ; i < n ; i++) {
            int idx = n-i-1;
            if (nums[i] < pivot) {
                res[s++] = nums[i];
            } 
            if (nums[idx] > pivot) {
                res[e--] = nums[idx];
            }
        }
        return res;
    }
};