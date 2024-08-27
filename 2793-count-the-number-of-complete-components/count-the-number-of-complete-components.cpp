class DSU {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> edges;
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n, 0);
        edges.resize(n, 0);
        for (int i = 0 ; i < n ; i++) {
            parent[i] = i;
        }
    }

    int findUlParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUlParent(parent[node]);
    }

    void unionBySize(int node1, int node2) {
        int ulParent1 = findUlParent(node1);
        int ulParent2 = findUlParent(node2);
        if (ulParent1 == ulParent2) {
            edges[ulParent1]++;
            return;
        }

        if (size[ulParent1] > size[ulParent2]) {
            size[ulParent1] += size[ulParent2];
            parent[ulParent2] = ulParent1;
            edges[ulParent1]++;
        } else {
            size[ulParent2] += size[ulParent1];
            parent[ulParent1] = ulParent2;
            edges[ulParent2]++;
        }
    }

};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu = DSU(n);
        for (auto i: edges) {
            dsu.unionBySize(i[0], i[1]);
        }
        int totalCompo = 0;
        for (int i = 0 ; i < n ; i++) {
            if (dsu.parent[i] == i) {
                int vert = dsu.size[i];
                if (dsu.edges[i] == ((vert*(vert-1))/2)) totalCompo++;
            }
        }
        return totalCompo;   
    }
};