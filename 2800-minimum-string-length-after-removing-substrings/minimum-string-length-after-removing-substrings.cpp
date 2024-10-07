class Solution {
public:
    int minLength(string s) {
        string temp;
        int start = 0;
        int size = s.size();
        while (start < size-1) {
            if ((s[start] == 'A' && s[start+1] == 'B') || (s[start] == 'C' && s[start+1] == 'D')) {
                s.erase(start,2);
                if (start > 0) start--;
            } else {
                start++;
            }
        }
        return s.size();
    }
};