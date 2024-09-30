class Solution {
public:
    bool isPalindrome(int x) {
        string orig = to_string(x);
        string rev = orig;
        reverse(rev.begin(), rev.end());
        if (orig == rev) return true;
        return false;
    }
};