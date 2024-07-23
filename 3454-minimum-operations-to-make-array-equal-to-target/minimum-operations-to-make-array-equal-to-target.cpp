class Solution {
public:
    long long solve(vector<long long> &diff, int i, int j) {
        long long total = 0;
        long long curr = 0;
        for (int k = i ; k <= j ; k++) {
            if (abs(diff[k]) > curr) {
                total += ((long long)abs(diff[k]) - (long long)curr);
            }
            curr = abs(diff[k]);
        }
        return total;
    }
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long totalOp = 0;
        int n = nums.size();
        if (n == 0) return 0;
        vector<long long> diff;
        for (int i = 0 ; i < n ; i++) {
            diff.push_back((long long)target[i]-(long long)nums[i]);
        }
        long long ans = 0;
        bool pos = diff[0] > 0 ? true : false;
        int start = 0;
        for (int i = 1 ; i < n ; i++) {
            if (diff[i] == 0) {
                ans += (solve(diff, start, i-1));
                start = i;
            } else if (diff[i-1] == 0) {
                pos = diff[i] > 0 ? true : false;
            } else if ((pos && diff[i] < 0) || (!pos && diff[i] > 0)) {
                ans += (solve(diff, start, i-1));
                start = i;
                pos = diff[i] > 0 ? true : false;
            }
        }
        ans += solve(diff, start, diff.size()-1);
        return ans;
    }
};