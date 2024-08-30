class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charCount(26,0);
        int n = s.size();
        int start=0,end=0;
        int maxLen = 0;
        int maxFreq = 0;
        while (end < n) {
            charCount[s[end]-'A']++;
            maxFreq = max(maxFreq, charCount[s[end]-'A']);
            while ((end-start+1)-maxFreq > k) {
                charCount[s[start]-'A']--;
                start++;
                maxFreq=0;
                for (int i = 0 ; i < 26 ; i++) {
                    maxFreq = max(maxFreq, charCount[i]);
                }
            }
            maxLen = max(maxLen,end-start+1);
            end++;
        }
        return maxLen;
    }
};