class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxTillNow = 0;
        int maxProfit = 0;
        for (int i = prices.size()-1 ; i>=0 ; i--) {
            int profit = maxTillNow-prices[i];
            maxProfit = max(maxProfit, profit);
            maxTillNow = max(maxTillNow, prices[i]);
        }
        return maxProfit;
    }
};