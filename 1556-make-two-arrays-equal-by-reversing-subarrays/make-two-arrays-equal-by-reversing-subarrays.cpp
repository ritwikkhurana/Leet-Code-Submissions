class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        int n1 = target.size();
        int n2 = arr.size();
        if (n1 != n2) return false;
        for (int i = 0 ; i < n1 ; i++) {
            if (arr[i] != target[i]) return false;
        }
        return true;
    }
};