class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adjList, int node, vector<int> &vis, vector<int> &pres, stack<int> &s) {
        vis[node] = 1;
        pres[node] = 1;
        for (auto i: adjList[node]) {
            if (!vis[i]) {
                bool output = dfs(adjList, i, vis, pres, s);
                if (!output) return false;
            } else if (pres[i]) return false;
        }
        pres[node] = 0;
        s.push(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adjList;
        for (auto i: prerequisites) {
            adjList[i[1]].push_back(i[0]);
        }
        int n = numCourses;
        vector<int> vis(n,0);
        vector<int> pres(n,0);
        vector<int> output;
        stack<int> s;
        for (int i = 0 ; i < n ; i++) {
            if (!vis[i]) {
                bool res = dfs(adjList, i, vis, pres, s);
                if (!res) return {};
            }
        }
        while (!s.empty()) {
            output.push_back(s.top());s.pop();
        }
        return output;
    }
};