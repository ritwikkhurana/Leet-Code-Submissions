class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        int n = numCourses;
        vector<int> inWt(n, 0);
        unordered_map<int, vector<int>> adjList;
        for (auto i: prerequisites) {
            adjList[i[1]].push_back(i[0]);
            inWt[i[0]]++;
        }
        queue<int> q;
        for (int i = 0 ; i < n ; i++) {
            if (inWt[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();q.pop();
            order.push_back(node);
            for (auto i: adjList[node]) {
                inWt[i]--;
                if (inWt[i] == 0) q.push(i);
            }
        }
        for (int i = 0 ; i < n ; i++) {
            if (inWt[i] != 0) return {};
        }
        return order;
    }
};