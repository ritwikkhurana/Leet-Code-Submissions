class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool flipFlag = false;
        int op = 0;
        for (int i: nums) {
            int val = flipFlag ? (i == 1 ? 0 : 1) : i;
            if (val == 1) continue;
            flipFlag = !flipFlag;
            op++;
        }
        return op;
    }
};