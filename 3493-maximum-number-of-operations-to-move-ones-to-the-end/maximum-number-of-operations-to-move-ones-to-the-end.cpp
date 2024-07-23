class Solution {
public:
    int maxOperations(string s) {
        int total = 0;
        int start = 0;
        int count = 0;
        while (start < s.size()) {
            if (s[start] == '1') {
                count++;
                start++;
            } else {
                total += (count);
                while (start < s.size() && s[start] == '0') start++;
            }
        }
        return total;
    }
};