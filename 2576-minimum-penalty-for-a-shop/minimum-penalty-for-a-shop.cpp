class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        unordered_map<int,pair<int,int>> ourmap;
        int yes=0,no=0;
        for (int i = 0 ; i < n ; i++) {
            if (customers[i] == 'Y') {
                yes++;
            } else {
                no++;
            }
            ourmap[i] = {yes,no};
        }
        int minPenalty = INT_MAX;
        int index = -1;
        for (int i = 0 ; i < n ; i++) {
            int penalty = 0;
            if (customers[i] == 'Y') {
                penalty++;
                penalty += (ourmap[i].second);
            } else {
                penalty += (ourmap[i].second-1);
            }
            penalty += (ourmap[n-1].first - ourmap[i].first);
            if (penalty < minPenalty) {
                minPenalty = penalty;
                index = i;
            }
        }
        if (ourmap[n-1].second < minPenalty) return n;
        return index;
    }
};