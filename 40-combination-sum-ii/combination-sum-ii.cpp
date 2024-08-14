class Solution {
public:
    void solve(vector<int>& candidates, int row, vector<vector<int>> &output, vector<int> &temp, int sum, int target) {
        if (sum == target) {
            output.push_back(temp);
            return;
        }
        if (sum >= target) return;
        if (row >= candidates.size()) return;
        for (int i = row ; i < candidates.size() ; i++) {
            if (i > row && candidates[i] == candidates[i-1]) continue;
            if (sum+candidates[i] > target) break;
            temp.push_back(candidates[i]);
            solve(candidates, i+1, output, temp, sum+candidates[i], target);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, output, temp, 0, target);
        sort(output.begin(), output.end());
        output.erase(unique(output.begin(), output.end()), output.end());
        return output;
    }
};