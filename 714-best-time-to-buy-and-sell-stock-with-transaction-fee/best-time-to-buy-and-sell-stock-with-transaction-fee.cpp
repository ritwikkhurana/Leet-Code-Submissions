class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> prev(2, 0);

        for (int i = n-1 ; i>=0 ; i--) {
            curr[0] = max(-prices[i] + prev[1], prev[0]);
            curr[1] = max(prices[i] + prev[0] - fee, prev[1]);
            prev = curr;
        }
        return curr[0];
    }
};