class Solution {
public:
    int findFarNode(unordered_map<int,vector<int>> adjList, int n) {
        queue<int> q;
        q.push(0);
        vector<int> vis(n, 0);
        vis[0] = 1;
        int farNode;
        while (!q.empty()) {
            int size = q.size();
            farNode = q.front();
            for (int i = 0 ; i < size ; i++) {
                int node = q.front(); q.pop();
                for (auto i: adjList[node]) {
                    if (!vis[i]) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
        return farNode;
    }

    int bfs(unordered_map<int,vector<int>> adjList, int n, int node) {
        queue<int> q;
        q.push(node);
        vector<int> vis(n, 0);
        vis[node] = 1;
        int maxDis = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0 ; i < size ; i++) {
                int node = q.front(); q.pop();
                for (auto i: adjList[node]) {
                    if (!vis[i]) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
            if (!q.empty()) maxDis++;
        }
        return maxDis;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adjList1, adjList2;
        for (auto i: edges1) {
            adjList1[i[0]].push_back(i[1]);
            adjList1[i[1]].push_back(i[0]);
        }

        for (auto i: edges2) {
            adjList2[i[0]].push_back(i[1]);
            adjList2[i[1]].push_back(i[0]);
        }
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        int farNode1 = findFarNode(adjList1, n1);
        int maxDis1 = bfs(adjList1, n1, farNode1);
        int farNode2 = findFarNode(adjList2, n2);
        int maxDis2 = bfs(adjList2, n2, farNode2);
        int half1 = maxDis1%2 == 0 ? maxDis1/2 : maxDis1/2+1;
        int half2 = maxDis2%2 == 0 ? maxDis2/2 : maxDis2/2+1;
        return max(maxDis1, max(maxDis2,half1 + half2 + 1));
    }
};