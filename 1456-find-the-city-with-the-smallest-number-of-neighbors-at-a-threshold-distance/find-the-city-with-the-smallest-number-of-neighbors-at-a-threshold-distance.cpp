class Solution {
public:
    void shortestPath(int n, unordered_map<int,vector<pair<int,int>>> &adjList, vector<vector<int>> &spath, int start
    , int threshold) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        spath[start][start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto i: adjList[node]) {
                int wt = i.second;
                int node2 = i.first;
                if (dis+wt <= threshold && dis+wt < spath[start][node2]) {
                    spath[start][node2] = dis+wt;
                    pq.push({dis+wt, node2});
                }
            }
        }
    }
    void floydWarshal(int n, vector<vector<int>> &edges, vector<vector<int>> &spath) {
        for (int i = 0 ; i < n ; i++) {
            spath[i][i] = 0;
        }
        for (auto i: edges) {
            spath[i[0]][i[1]] = i[2];
            spath[i[1]][i[0]] = i[2];
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                for (int k = 0 ; k < n ; k++) {
                    if (j == i || k == i) continue;
                    if (spath[j][i] == INT_MAX || spath[i][k] == INT_MAX) continue;
                    spath[j][k] = min(spath[j][k], spath[j][i]+spath[i][k]);
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>> adjList;
        for (auto i: edges) {
            adjList[i[0]].push_back({i[1],i[2]});
            adjList[i[1]].push_back({i[0],i[2]});
        }
         vector<vector<int>> spath(n, vector<int>(n, INT_MAX));
         floydWarshal(n, edges, spath);
         int minCities = INT_MAX;
         int city;
         for (int i = n-1 ; i >=0  ; i--) {
            int cities = 0;
            for (int j = 0 ; j < n ; j++) {
                if (i!=j && spath[i][j] != INT_MAX && spath[i][j] <= distanceThreshold) {
                    cities++;
                }
            }
            if (cities < minCities) {
                minCities = cities;
                city = i;
            }
         }
        //  for (int i = 0 ; i < n ; i++) {
        //     shortestPath(n, adjList, spath, i, distanceThreshold);
        //  }
        //  int minCities = INT_MAX;
        //  int city;
        //  for (int i = n-1 ; i>=0 ; i--) {
        //     int totalCities = 0;
        //     for (int j: spath[i]) {
        //         if (j != INT_MAX) totalCities++;
        //     }
        //     totalCities--;
        //     if (minCities > totalCities) {
        //         minCities = totalCities;
        //         city = i;
        //     }
        //  }
        return city;
    }
};