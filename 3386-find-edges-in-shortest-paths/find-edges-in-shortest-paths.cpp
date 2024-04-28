class Solution {
public:
    void storeAllPaths(vector<pair<int,vector<int>>> spath, int node, unordered_set<string> &hashset) {
        if (node == 0 || node == INT_MAX) return;
        for (auto it: spath[node].second) {
            string key = to_string(it) + "|" + to_string(node);
            hashset.insert(key);
            storeAllPaths(spath, it, hashset);
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int>>> adjList;
        for (auto it: edges) {
            adjList[it[0]].push_back({it[1],it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }
        vector<pair<int,vector<int>>> spath(n, {INT_MAX,{}});
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        spath[0] = {0,{}};
        pq.push({0,0});
        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for (auto it: adjList[node]) {
                int node2 = it.first;
                int dis2 = it.second;
                if (dis + dis2 < spath[node2].first) {
                    spath[node2] = {dis + dis2, {node}};
                    pq.push({spath[node2].first, node2});
                } else if (dis + dis2 == spath[node2].first) {
                    spath[node2].second.push_back(node);
                }
            }
        }
        unordered_set<string> hashSet;
        storeAllPaths(spath, n-1, hashSet);
        vector<bool> ans;
        for (auto it: edges) {
            string key1 = to_string(it[0]) + "|" + to_string(it[1]);
            if (hashSet.find(key1) != hashSet.end()) {
                ans.push_back(true);
            } else {
                string key2 = to_string(it[1]) + "|" + to_string(it[0]);
                if (hashSet.find(key2) != hashSet.end()) {
                    ans.push_back(true);
                } else {
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};