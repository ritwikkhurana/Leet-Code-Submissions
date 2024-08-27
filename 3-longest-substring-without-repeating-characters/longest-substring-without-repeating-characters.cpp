class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> ourmap;
        int maxLen=0;
        int currLen=0;
        int start=0,end=0;
        while (end < s.size()) {
            if (ourmap[s[end]] == 0) {
                ourmap[s[end]]++;
                maxLen = max(maxLen,end-start+1);
                end++;
            } else {
                while(s[start] != s[end]) {
                    ourmap[s[start]]--;
                    start++;
                }
                ourmap[s[start]]--;
                start++;
            }
        }
        return maxLen;
    }
};