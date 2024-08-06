class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op = 0;
        for (int i: nums) {
            if (i%3 != 0) op++;
        }
        return op;
    }
};