class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int,int> ourmap;
        int flag = 0;
        for (int i = n-1 ; i >=0 ; i--) {
            for (int j = 0 ; j < n ; j++) {
                int cell;
                if (flag == 1) {
                    cell = (n-1-i) * n + (n-j);
                } else {
                    cell = (n-1-i) * n + j + 1;
                }
                if (board[i][j] != -1) {
                    ourmap[cell] = board[i][j];
                }
            }
            flag = 1-flag;
        }
        vector<int> vis(n*n + 1, 0);
        queue<pair<int,int>> q;
        q.push({1,0});
        vis[1] = 1;
        while (!q.empty()) {
            int node = q.front().first;
            int moves = q.front().second;
            q.pop();
            if (node == n*n) return moves;
            for (int i = node+1 ; i <= min(node+6, n*n) ; i++) {
                if (vis[i] == 1) continue;
                if (ourmap.find(i) != ourmap.end()) {
                    q.push({ourmap[i], moves+1});
                } else {
                    q.push({i, moves+1});
                }
                vis[i] = 1;
            } 
        }
        return -1;
    }
};