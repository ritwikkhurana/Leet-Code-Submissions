class Solution {
    int dp[21][21][21][21];
public:
    int getCost(vector<int> &horizontalCut, vector<int> &verticalCut, int hs, int he, int vs, int ve) {
        if (hs>=he && vs>=ve) return 0;
        int minCost = INT_MAX;
        if (dp[hs][he][vs][ve] != -1) return dp[hs][he][vs][ve];
        for (int i = hs ; i < he ; i++) {
            int cost = horizontalCut[i] + getCost(horizontalCut, verticalCut, hs, i, vs, ve) + 
            getCost(horizontalCut, verticalCut, i+1, he, vs, ve);
            minCost = min(minCost, cost);
        }

        for (int i = vs ; i < ve ; i++) {
            int cost = verticalCut[i] + getCost(horizontalCut, verticalCut, hs, he, vs, i) + 
            getCost(horizontalCut, verticalCut, hs, he, i+1, ve);
            minCost = min(minCost, cost);
        }
        return dp[hs][he][vs][ve] = minCost;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        memset(dp, -1, sizeof(dp));
        return getCost(horizontalCut, verticalCut, 0,horizontalCut.size(), 0, verticalCut.size());
    }
};