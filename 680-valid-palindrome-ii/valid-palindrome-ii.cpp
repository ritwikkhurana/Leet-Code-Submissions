class Solution {
public:
    bool isValidSubPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true; 
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int start=0,end=n-1;
        while (start <= end) {
            if (s[start] != s[end]) {
                if (isValidSubPalindrome(s,start+1, end) || isValidSubPalindrome(s,start,end-1)) return true;
                return false;
            } else {
                start++;
                end--;
            }
        }
        return true;
    }
};