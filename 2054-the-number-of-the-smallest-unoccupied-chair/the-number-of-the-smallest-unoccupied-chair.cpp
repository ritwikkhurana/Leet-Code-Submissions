class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> arrival;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> dep;
        map<int,int> chairs;
        map<int,int> unocc;
        int totalChairs=0;
        for (int i = 0 ; i < times.size() ; i++) {
            arrival.push({times[i][0], i});
            dep.push({times[i][1], i});
        }
        while (!arrival.empty()) {
            if (arrival.top().first < dep.top().first) {
                int chair;
                if (unocc.empty()) {
                    chair = totalChairs;
                    totalChairs++;
                } else {
                    chair = unocc.begin()->first;
                    unocc.erase(unocc.begin()->first);
                }
                chairs[arrival.top().second] = chair;
                if (arrival.top().second == targetFriend) return chair;
                arrival.pop();
            } else {
                unocc[chairs[dep.top().second]] = 1;
                chairs.erase(dep.top().second);
                dep.pop();
            }
        }
        return 0;
    }
};