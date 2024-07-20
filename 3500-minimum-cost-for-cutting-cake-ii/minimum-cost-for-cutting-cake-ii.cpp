class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        priority_queue<int> h,v;
        int hm=1,vm=1;
        long long totalCost = 0;
        for (int i: horizontalCut) {h.push(i);}
        for (int i: verticalCut) {v.push(i);}
        while (!h.empty() && !v.empty()) {
            int htop = h.top();
            int vtop = v.top();
            if (htop >= vtop) {
                h.pop();
                vm++;
                totalCost += ((long long)htop* (long long)hm);
            } else {
                v.pop();
                hm++;
                totalCost += ((long long) vtop * (long long)vm);
            }
        }
        while (!h.empty()) {
            int htop = h.top();h.pop();
            totalCost += ((long long)htop * (long long)hm);
        }
        while (!v.empty()) {
            int vtop = v.top();v.pop();
            totalCost += ((long long)vtop * (long long)vm);
        }
        return totalCost;
    }
};