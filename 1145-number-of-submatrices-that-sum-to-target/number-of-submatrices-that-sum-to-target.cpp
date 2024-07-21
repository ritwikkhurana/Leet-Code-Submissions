class Solution {
public:
    int countSub(vector<int> &dp, int row, int m, int target) {
        unordered_map<int,int> ourmap;
        int totalSum = 0;
        int total = 0;
        for (int i = 0 ; i < m ; i++) {
            totalSum += dp[i];
            if (totalSum == target) total++;
            if (ourmap.find(totalSum-target) != ourmap.end()) {
                total += ourmap[totalSum-target];
            }
            ourmap[totalSum]++;
        }
        return total;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = 0;
        for (int i = 0 ; i < n ; i++) {
            vector<int> temp(m, 0);
            for (int j = i ; j < n ; j++) {
                for (int k = 0 ; k < m ; k++) {
                    temp[k] += (matrix[j][k]);
                }
                total += (countSub(temp, i, m, target));
            }
        }
        return total;
    }
};