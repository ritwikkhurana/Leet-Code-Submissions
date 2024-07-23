class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> ourmap;
        if (s.size() == 0) return 0;
        for (char c : s) {
            ourmap[c]++;
            if (ourmap[c] == 3) {
                ourmap[c] -= 2;
            }
        }
        int finalLen = 0;
        for (auto i: ourmap) {
            finalLen += (i.second);
        }
        return finalLen;
    }
};