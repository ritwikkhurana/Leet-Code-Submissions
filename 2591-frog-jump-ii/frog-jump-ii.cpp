class Solution {
public:
    int maxJump(vector<int>& stones) {
        int maxJump = 0;
        int prev = 0;
        int n = stones.size();
        if (n == 2) return stones[1] - stones[0];
        for (int i = 2 ; i < stones.size() ; i+=2) {
            int jump = stones[i] - stones[prev];
            maxJump = max(jump, maxJump);
            prev = i;
        }
        prev = 0;
        for (int i = 1 ; i < stones.size() ; i+=2) {
            int jump = stones[i] - stones[prev];
            maxJump = max(jump, maxJump);
            prev = i;
        }
        maxJump = max(stones[n-1] - stones[n-2], maxJump);
        return maxJump;
    }
};