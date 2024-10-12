class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int size = croakOfFrogs.size();
        unordered_map<char,int> ourmap;
        int frogs = 0;
        for (char c: croakOfFrogs) {
            if (c == 'c') {
                if (ourmap['k'] == 0) {
                    frogs++;
                } else {
                    ourmap['k']--;
                }
            } else if (c == 'r') {
                if (ourmap['c'] == 0) return -1;
                ourmap['c']--;
            } else if (c == 'o') {
                if (ourmap['r'] == 0) return -1;
                ourmap['r']--;
            } else if (c == 'a') {
                if (ourmap['o'] == 0) return -1;
                ourmap['o']--;
            } else if (c == 'k') {
                if (ourmap['a'] == 0) return -1;
                ourmap['a']--;
            }
            ourmap[c]++;
        }
        if (ourmap['c'] > 0 || ourmap['r'] > 0 || ourmap['o'] > 0 || ourmap['a'] > 0) return -1;
        return frogs;
    }
};