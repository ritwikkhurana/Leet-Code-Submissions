class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCount(32, 0);
        for (int i: candidates) {
            for (int j = 0 ; j < 32 ; j++) {
                int bit = (i >> j) & 1;
                if (bit == 1) bitCount[j]++;
            }
        }
        int maxCandidates = 0;
        for (int i = 0 ; i < 32 ; i++) {
            maxCandidates = max(maxCandidates, bitCount[i]);
        }
        return maxCandidates;
    }
};