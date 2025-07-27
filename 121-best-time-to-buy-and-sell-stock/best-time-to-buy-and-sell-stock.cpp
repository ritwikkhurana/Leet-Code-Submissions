class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = prices[0];
        int n = prices.size();
        int maxProfit = 0;
        for (int i = 1; i < n ; i++) {
            maxProfit = max(maxProfit, prices[i]-minTillNow);
            minTillNow = min(minTillNow, prices[i]);
        }
        return maxProfit;
    }
};