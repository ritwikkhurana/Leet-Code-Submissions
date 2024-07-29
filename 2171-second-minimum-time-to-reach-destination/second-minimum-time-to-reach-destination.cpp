class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> adjList;
        for (auto i: edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<pair<int,int>> minDis(n+1, {INT_MAX-1,INT_MAX});
        minDis[1] = {0,INT_MAX};
        pq.push({0,1});
        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for (auto i: adjList[node]) {
                int node2 = i;
                int dis2 = time;
                int arr = dis+dis2;
                int leav = arr;
                int color = (arr/change)%2 == 0 ? 1 : 0;
                if (color == 0) leav += (change-(arr%change));
                if (arr < minDis[node2].first) {
                    minDis[node2].second = minDis[node2].first;
                    minDis[node2].first = arr;
                    pq.push({leav, node2});
                } else if (arr > minDis[node2].first && arr < minDis[node2].second) {
                    minDis[node2].second = arr;
                    pq.push({leav, node2});
                }
            }
        }
        return minDis[n].second;
    }
};