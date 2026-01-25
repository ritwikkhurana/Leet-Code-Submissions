class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(k+1, vector<int>(2, 0));
        vector<vector<int>> prev(k+1, vector<int>(2, 0));

        for (int i = n-1 ; i>=0 ; i--) {
            for (int j = 1 ; j <= k ; j++) {
                curr[j][0] = max(-prices[i] + prev[j][1], prev[j][0]);
                curr[j][1] = max(prices[i] + prev[j-1][0], prev[j][1]);
                prev = curr;
            }
        }
        return curr[k][0];
    }
};