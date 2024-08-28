class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int total = 0;
        int a=-1,b=-1,c=-1;
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == 'a') {
                a=i;
            } else if (s[i] == 'b') {
                b=i;
            } else {
                c=i;
            }
            if (a==-1 || b==-1 || c==-1) continue;
            int reqIndex = min(a,min(b,c));
            total += (reqIndex+1);
        }
        return total;
    }
};