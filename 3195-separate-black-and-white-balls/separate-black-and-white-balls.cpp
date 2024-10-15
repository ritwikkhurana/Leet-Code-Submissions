class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        int startIndex = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == '1') continue;
            steps += (i-startIndex);
            startIndex++;
        }
        return steps;
    }
};