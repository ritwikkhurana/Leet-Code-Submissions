class Solution {
public:
    bool helper(vector<int>& arr, int index, vector<int> &vis) {
        if (arr[index] == 0) {
            return true;
        }
        vis[index] = 1;
        int forward = index + arr[index];
        if (forward < arr.size() && !vis[forward]) {
            bool res = helper(arr, forward, vis);
            if (res) {
                return true;
            }
        }

        int back = index - arr[index];
        if (back >= 0 && !vis[back]) {
            bool res = helper(arr, back, vis);
            if (res) {
                return true;
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        return helper(arr, start, vis);
    }
};