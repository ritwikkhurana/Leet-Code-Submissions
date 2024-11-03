class Solution {
public:
    void shift(string &a) {
        char temp = a[0];
        int i = 1;
        while (i < a.size()) {
            a[i-1] = a[i];
            i++;
        }
        a[a.size()-1] = temp;
    }
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        for (int i = 0 ; i < s.size() ; i++) {
            shift(s);
            if (s == goal) return true;
        }
        return false;
    }
};