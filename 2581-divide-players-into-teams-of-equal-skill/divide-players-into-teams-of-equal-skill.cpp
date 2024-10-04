class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long totalChem = 0;
        int n = skill.size();
        long long sum = 0;
        for (int i: skill) {
            sum = (sum+(long long)i);
        }
        int sumReq = ((long long)sum*2)/n;
        unordered_map<int,int> ourmap;
        int found = 0;
        for (int i: skill) {
            if (ourmap[sumReq-i] > 0) {
                totalChem = (totalChem + ((long long)i * (sumReq-i)));
                found++;
                ourmap[sumReq-i]--;
            } else {
                ourmap[i]++;
            }
        }
        if (found < n/2) return -1;
        return totalChem;
    }
};