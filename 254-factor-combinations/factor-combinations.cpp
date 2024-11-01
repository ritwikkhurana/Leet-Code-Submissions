class Solution {
public:
    void help(int n, vector<int> &factors, vector<vector<int>> &output) {
        if (n == 1) return;
        int start = factors.empty() ? 2 : factors.back();
        int end = sqrt(n);
        for (int i = start ; i <= end ; i++) {
            if (n%i != 0) continue;
            factors.push_back(i);
            factors.push_back(n/i);
            output.push_back(factors);
            factors.pop_back();
            help(n/i, factors, output);
            factors.pop_back();
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<int> factors;
        vector<vector<int>> output;
        help(n, factors, output);
        return output;
    }
};