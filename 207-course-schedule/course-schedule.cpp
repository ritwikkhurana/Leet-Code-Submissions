class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adjList;
        vector<int> inDeg(numCourses, 0);
        queue<int> q;

        for (int i = 0 ; i < prerequisites.size() ; i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDeg[prerequisites[i][0]]++;
        }

        for (int i = 0 ; i < numCourses ; i++) {
            if (inDeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto i : adjList[node]) {
                inDeg[i]--;
                if (inDeg[i] == 0) q.push(i);
            }
        }
        if (!q.empty()) return false;

        for (int i = 0 ; i < numCourses ; i++) {
            if (inDeg[i] != 0) return false;
        }
        return true;
    }
};