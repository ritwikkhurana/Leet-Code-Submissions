class Solution {
public:
    void computeLPS(vector<int> &lps, string needle) {
        int len=0,i=0;
        lps[0] = 0;
        i = 1;
        while (i < needle.size()) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else if (len != 0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(), 0);
        computeLPS(lps, needle);
        int i=0,j=0;
        while (j < haystack.size()) {
            if (haystack[j] == needle[i]) {
                i++;
                j++;
                if (i == needle.size()) return j-i;
            } else {
                if (i != 0) {
                    i = lps[i-1];
                } else {
                    j++;
                }
            }
            
        }
        return -1;  
    }
};