class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> output(n, 0);
        map<int,vector<int>> ourmap;
        for (int i = 0 ; i < n ; i++) {
            ourmap[arr[i]].push_back(i);
        }
        int rank = 1;
        for (auto i : ourmap) {
            for (int index : i.second) {
                output[index] = rank;
            }
            rank++;
        }
        return output;
    }
};