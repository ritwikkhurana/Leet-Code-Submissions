class Solution {
public:
    int minSwaps(string s) {
        stack<char> bal;
        int balanced = 0;
        for (char c: s) {
            if (c == '[') {
                bal.push('[');
            } else {
                if (!bal.empty()) {
                    balanced++;
                    bal.pop();
                }
            }
        }
        int totalPairs = s.size()/2;
        int unbal = totalPairs - balanced;
        vector<int> dp(unbal+1, 0);
        if (unbal <= 2) return unbal == 0 ? 0 : 1;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3 ; i <= unbal ; i++) {
            dp[i] = 1 + dp[i-2];
        }
        return dp[unbal]; 
    }
};