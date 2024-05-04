class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<pair<int,int>> curr(3, {0,0});
        vector<pair<int,int>> next(3, {0,0});
        curr[1] = {0,prices[n-1]};
        curr[2] = {0,prices[n-1]};
        for (int i = n-2 ; i>= 0 ; i--) {
            for (int j = 0 ; j <= 2 ; j++) {
                if (j == 0) {
                    continue;
                }
                int buy = max(curr[j].first, -prices[i] + curr[j].second);
                int sell = max(curr[j].second, prices[i] + curr[j-1].first);
                next[j] = {buy, sell};
            }
            curr = next;
        }
        return curr[2].first;
    }
};